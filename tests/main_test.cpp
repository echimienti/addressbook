/*
 * main_test.cpp
 *
 *  Created on: May 9, 2017
 *  @author: E. Chimienti
 *  @version 0.1 09/05/17
 *
 */
#include <gtest/gtest.h>

#include "../addressbook.h"
#include "../libcsvfile/csvfile.h"
#include "../addressbook.cpp"
#include "../libcsvfile/csvfile.cpp"
#include "addressbook_test.h"
#include "csvfile_test.h"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}