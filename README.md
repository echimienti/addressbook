# addressbook
addressbook storage in csv file (comma separated file) <br />


# Checkout code:
git clone https://github.com/echimienti/addressbook.git <br />


# For compiling:
cd addressbook <br />
make <br />


# For make test install/configure first:
sudo apt-get install libgtest-dev <br />
sudo apt install cmake <br />
cd /usr/src/gtest <br />
sudo cmake CMakeLists.txt <br />
sudo make <br />
sudo cp *.a /usr/lib <br />
<br />
make test <br />


# Create documentation:
make doc <br />
