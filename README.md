# addressbook
addressbook storage in csv file (comma separated file) <br />
This program uses csvfile module created by same author and is included as submodule <br />

# Checkout code:
git clone https://github.com/echimienti/addressbook.git <br />


# For compiling:
on Ubuntu: sudo apt install g++ <br />
on Centos: sudo yum group install "Development Tools" <br />
cd addressbook <br />
git submodule update --init --recursive <br />
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
For running make doc install: <br />
sudo apt install doxygen <br />
sudo apt install libkgraphviewer2 <br />
make doc <br />


# Get contacts from Google contacts:
with your browse go to: https://contacts.google.com/?hl=en <br />
On the left in the tree click on Export -> select either Export as Google CSV or Outlook CSV (both are supported by the program) <br />
In your Downloads folder you will have a file named contacts.csv <br />
copy this file to in the addressbook folder and name it address.csv ad the program will work with csv file name address.csv <br />
You can also start this program without these steps, a new empty adress.csv will be created <br />


# Start addressbook program:
./addressbook_main <br />
