#build_all.sh
cd src
for f in *.cpp ; do ./build.sh ${f%.cpp} ; done
for f in *.cpp ; do mv ${f%.cpp} ../build/ ; done