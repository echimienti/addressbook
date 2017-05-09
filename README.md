# addressbook
addressbook storage in csv file (comma separated file)


# Checkout code:
git clone https://github.com/echimienti/addressbook.git


# For compiling:
cd addressbook
make


# For make test install/configure first:
sudo apt-get install libgtest-dev
sudo apt install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib

make test


# Create documentation:
make doc
