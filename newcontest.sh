#for fast mkdir and basefiles
#for further info., just go see function sub
#maxwill lin
#ver 0 done 2020/3/4 22:19

#!/bin/bash

function sub()
{
  mkdir $1
  cp basefile/basefile.cpp $1/A.cpp
  cp basefile/basefile.cpp $1/B.cpp
  cp basefile/basefile.cpp $1/C.cpp
  cp basefile/basefile.cpp $1/D.cpp
  cp basefile/basefile.cpp $1/E.cpp
  cp basefile/basefile.cpp $1/F.cpp
}


if [ $# -eq 1 ]; then
  sub $1
elif [ $# -eq 0 ]; then
  read -p "input folder name:" FOLDERNAME
  sub ${FOLDERNAME}
else
  echo "Usage : newcontest FOLDERNAME or newcontest"
fi

sleep 0.5
