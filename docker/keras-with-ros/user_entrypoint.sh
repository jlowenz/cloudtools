#!/bin/bash

# Add local user
# Either use the LOCAL_USER_ID if passed in at runtime or
# fallback

USER_ID=${LOCAL_USER_ID:-9001}
GROUP_ID=${LOCAL_GROUP_ID:-9001}

echo "Starting with UID : $USER_ID"
groupadd --gid $GROUP_ID docker_user
groupadd --gid 1100 vglusers
useradd --shell /bin/bash -u $USER_ID -o -c "" user
echo "user:user" | chpasswd
export HOME=/home/user
#touch $HOME/.Xauthority
cp /tmp/.symrc $HOME/.symrc
chown -R user:docker_user /home/user $HOME/.Xauthority $HOME/.symrc

exec /usr/sbin/chroot --userspec=user:docker_user --groups=sudo,vglusers / "$@"
