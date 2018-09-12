# Overview

This software library computes a 3D curve skeleton for a point cloud. It utilizes local L1-median points to iteratively estimate a skeleton, keeping track of multiple branches and bridge points. 

This is an adapted software package for the SIGGRAPH 2013 paper:

```bibtex
  @article{Huang:2013:LMS:2461912.2461913,
    author = {Huang, Hui and Wu, Shihao and Cohen-Or, Daniel and Gong, Minglun and Zhang, Hao   and Li, Guiqing and Chen, Baoquan},
    title = {L1-medial Skeleton of Point Cloud},
    journal = {ACM Trans. Graph.},
    issue_date = {July 2013},
    volume = {32},
    number = {4},
    month = jul,
    year = {2013},
    issn = {0730-0301},
    pages = {65:1--65:8},
    articleno = {65},
    numpages = {8},
    url = {http://doi.acm.org/10.1145/2461912.2461913},
    doi = {10.1145/2461912.2461913},
    acmid = {2461913},
    publisher = {ACM},
    address = {New York, NY, USA},
    keywords = {L1-median, curve skeleton, point cloud, regularization},} 
```

It's been modified to work on GNU/Linux as a shared library for processing point clouds stored as PCD files. In addition, it's built using the ROS framework for integration into robotics projects. Out

# Dependencies

- Qt (why???)
- PCL 1.8.1
- libann (approximate nearest neighbor) 1.1.2
- VCGLib (GPL)
- Contains portions of MeshLab source (GPL) 
