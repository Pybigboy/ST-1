// Copyright 2025 UNN-CS

#include <gtest/gtest.h>

#include <cstdint>

#include "alg.h"

TEST(PrimeTest, CheckPrimeEdgeCases) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(97));
  EXPECT_FALSE(checkPrime(100));
}

TEST(PrimeTest, CheckPrimeLargeNumbers) {
  EXPECT_TRUE(checkPrime(104729));  // 10000-е простое число
  EXPECT_FALSE(checkPrime(104730));
}

TEST(PrimeTest, NthPrimeSmallValues) {
  EXPECT_EQ(nPrime(1), 2);
  EXPECT_EQ(nPrime(2), 3);
  EXPECT_EQ(nPrime(5), 11);
}

TEST(PrimeTest, NthPrimeLargeValue) { EXPECT_EQ(nPrime(100), 541); }

TEST(PrimeTest, NextPrimeBasic) {
  EXPECT_EQ(nextPrime(10), 11);
  EXPECT_EQ(nextPrime(14), 17);
}

TEST(PrimeTest, NextPrimeAfterLarge) { EXPECT_EQ(nextPrime(1000), 1009); }

TEST(PrimeTest, SumPrimeSmallRange) {
  EXPECT_EQ(sumPrime(10), 17);
  EXPECT_EQ(sumPrime(20), 77);
}

TEST(PrimeTest, SumPrimeMediumRange) { EXPECT_EQ(sumPrime(50), 328); }

TEST(PrimeTest, SumPrimeLargeRange) { EXPECT_EQ(sumPrime(100), 1060); }

TEST(PrimeTest, CombinedEdgeCases) {
  EXPECT_EQ(nextPrime(nPrime(5)), 13);
  EXPECT_EQ(sumPrime(nPrime(5)), 17);
}

TEST(PrimeTest, MultiplePrimeChecks) {
  for (uint64_t num : {31, 37, 41, 43, 47}) {
    EXPECT_TRUE(checkPrime(num)) << "Failed for " << num;
  }
}

TEST(PrimeTest, NestedTest) {
  uint64_t primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  for (int i = 0; i < 10; i++) {
    SCOPED_TRACE("Checking nth prime for index " + std::to_string(i + 1));
    EXPECT_EQ(nPrime(i + 1), primes[i]);
  }
}
