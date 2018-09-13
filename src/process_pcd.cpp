#include "CMesh.h"
#include "DataMgr.h"
#include "Skeletonization.h"

#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

int
main(int argc, char** argv)
{
  double radius;
  double mu_repulsion;
  double h_gaussian;
  
  // parse the CLI arguments
  po::variables_map vm;
  po::options_description opts;
  opts.add_options()
    ("help,h", "Ask for help")
    ("initial-radius,r",
     po::value<double>(&radius)->default_value(0.05),
     "Initial radius for local point neighborhoods")
    ("mu-repulsion,m",
     po::value<double>(&mu_repulsion)->default_value(0.35),
     "Repulsion value for conditional regularization")
    ("h-gaussian,g",
     po::value<double>(&h_gaussian)->default_value(4),
     "H-Gaussian value")
    ("input-file", "Input PCD files")
    ; 

  po::positional_options_description pos;
  pos.add("input-file", 1);

  po::store(po::command_line_parser(argc,argv)
            .options(opts).positional(pos).run(), vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << opts << std::endl;
    exit(0);
  }

  if (vm.count("input-file") < 1) {
    std::cerr << "Need at least one PCD file" << std::endl;
    exit(1);
  }
  
  // prepare the parameter set
  RichParameterSet* datapara = global_paraMgr.getDataParameterSet();
  RichParameterSet* skelpara = global_paraMgr.getSkeletonParameterSet();
  auto grid_radius = DoubleValue(radius);
  auto mu = DoubleValue(mu_repulsion);
  datapara->setValue("CGrid Radius", grid_radius);
  skelpara->setValue("Repulsion Mu", mu);
  skelpara->setValue("CGrid Radius", grid_radius);
  skelpara->setValue("Initial Radius", grid_radius);
  skelpara->setValue("H Gaussian Para", DoubleValue(h_gaussian));
  skelpara->setValue("Run Auto Wlop One Step", BoolValue(true));

  // load the specified PCD file
  std::string input = vm["input-file"].as<std::string>();
  DataMgr input_data(datapara);
  if (input.find(".pcd") != std::string::npos) {
    input_data.loadPCD(input, false);
  } else {
    input_data.loadPlyToOriginal(input.c_str());
  }
  input_data.loadPCD(input, true); // samples are original
  //input_data.downSamplesByNum(true);
  
  Skeletonization skel_algo(skelpara);

  // run the skeletonization algorithm
  skel_algo.run_full(&input_data);

  // extract the skeleton
  Skeleton* skel = input_data.getCurrentSkeleton();

  // save the skeleton as a PCD file
  fs::path outp(input);
  outp.replace_extension(".skel.pcd");
  skel->saveToPCD(outp.string());

  // optionally visualize
  
  return 0;
}
