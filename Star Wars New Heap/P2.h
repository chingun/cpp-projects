#ifndef P2_H
#define P2_H

#include <cassert>
#include <sstream>
#include <string>
#include <vector>

class P2 {
public:
  static void PR_init(std::stringstream& ss,
                      int seed,
                      int num_generals,
                      int num_planets,
                      int num_deployments,
                      int arrival_rate);
  // Don't need to read further than this, unless you want to learn about
  // Mersenne Twister implementation
private:

  /**
   * mt.h: Mersenne Twister header file
   *
   * Jason R. Blevins <jrblevin@sdf.lonestar.org>
   * Durham, March  7, 2007
   */

  /**
   * Mersenne Twister.
   *
   * M. Matsumoto and T. Nishimura, "Mersenne Twister: A
   * 623-dimensionally equidistributed uniform pseudorandom number
   * generator", ACM Trans. on Modeling and Computer Simulation Vol. 8,
   * No. 1, January pp.3-30 (1998).
   *
   * http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html.
   */
  class MersenneTwister
  {
  public:
      MersenneTwister(void);
      ~MersenneTwister(void);

      void print(void);

      void init_genrand(unsigned long s);

      unsigned long genrand_unsigned_long(void);

  private:
      static const int N                    = 624;
      static const int M                    = 397;
      // constant vector a
      static const unsigned long MATRIX_A   = 0x9908b0dfUL;
      // most significant w-r bits
      static const unsigned long UPPER_MASK = 0x80000000UL;
      // least significant r bits
      static const unsigned long LOWER_MASK = 0x7fffffffUL;

      unsigned long* mt_;                  // the state vector
      int mti_;                            // mti == N+1 means mt not initialized

      unsigned long* init_key_;            // Storage for the seed vector
      int key_length_;                     // Seed vector length
      unsigned long s_;                    // Seed integer
      bool seeded_by_array_;               // Seeded by an array
      bool seeded_by_int_;                 // Seeded by an integer
  };
};

#endif 
