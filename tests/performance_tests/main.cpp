// Copyright (c) 2012-2013 The Cryptonote developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "performance_tests.h"
#include "performance_utils.h"

// tests
#include "construct_tx.h"
#include "check_ring_signature.h"
#include "derive_public_key.h"
#include "derive_secret_key.h"
#include "generate_key_derivation.h"
#include "generate_key_image.h"
#include "generate_key_image_helper.h"
#include "is_out_to_acc.h"
#include "keccak_test.h"

int main(int argc, char** argv)
{
  set_process_affinity(1);
  set_thread_high_priority();

  performance_timer timer;
  timer.start();

  //TEST_PERFORMANCE0(test_keccak);
  //TEST_PERFORMANCE0(test_keccak_alt1);  
   
  //TEST_PERFORMANCE0(test_keccak_generic);
  //TEST_PERFORMANCE0(test_keccak_generic_with_mul);
  
  TEST_PERFORMANCE1(test_wild_keccak, 400);
  TEST_PERFORMANCE1(test_wild_keccak2, 400);
  
  TEST_PERFORMANCE1(test_wild_keccak, 40000);
  TEST_PERFORMANCE1(test_wild_keccak2, 40000);
  TEST_PERFORMANCE1(test_wild_keccak, 4000000);
  TEST_PERFORMANCE1(test_wild_keccak2, 4000000);
  TEST_PERFORMANCE1(test_wild_keccak, 40000000);
  TEST_PERFORMANCE1(test_wild_keccak2, 40000000);
  TEST_PERFORMANCE1(test_wild_keccak, 100000000);
  TEST_PERFORMANCE1(test_wild_keccak2, 100000000);

  measure_keccak_over_scratchpad();
  /*
  TEST_PERFORMANCE2(test_construct_tx, 1, 1);
  TEST_PERFORMANCE2(test_construct_tx, 1, 2);
  TEST_PERFORMANCE2(test_construct_tx, 1, 10);
  TEST_PERFORMANCE2(test_construct_tx, 1, 100);
  TEST_PERFORMANCE2(test_construct_tx, 1, 1000);

  TEST_PERFORMANCE2(test_construct_tx, 2, 1);
  TEST_PERFORMANCE2(test_construct_tx, 2, 2);
  TEST_PERFORMANCE2(test_construct_tx, 2, 10);
  TEST_PERFORMANCE2(test_construct_tx, 2, 100);

  TEST_PERFORMANCE2(test_construct_tx, 10, 1);
  TEST_PERFORMANCE2(test_construct_tx, 10, 2);
  TEST_PERFORMANCE2(test_construct_tx, 10, 10);
  TEST_PERFORMANCE2(test_construct_tx, 10, 100);

  TEST_PERFORMANCE2(test_construct_tx, 100, 1);
  TEST_PERFORMANCE2(test_construct_tx, 100, 2);
  TEST_PERFORMANCE2(test_construct_tx, 100, 10);
  TEST_PERFORMANCE2(test_construct_tx, 100, 100);

  TEST_PERFORMANCE1(test_check_ring_signature, 1);
  TEST_PERFORMANCE1(test_check_ring_signature, 2);
  TEST_PERFORMANCE1(test_check_ring_signature, 10);
  TEST_PERFORMANCE1(test_check_ring_signature, 100);

  TEST_PERFORMANCE0(test_is_out_to_acc);
  TEST_PERFORMANCE0(test_generate_key_image_helper);
  TEST_PERFORMANCE0(test_generate_key_derivation);
  TEST_PERFORMANCE0(test_generate_key_image);
  TEST_PERFORMANCE0(test_derive_public_key);
  TEST_PERFORMANCE0(test_derive_secret_key);
  */
  std::cout << "Tests finished. Elapsed time: " << timer.elapsed_ms() / 1000 << " sec" << std::endl;

  return 0;
}
