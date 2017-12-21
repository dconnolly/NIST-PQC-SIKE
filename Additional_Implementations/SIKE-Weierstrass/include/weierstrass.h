//
// SIKE-Weierstrass
//
// InfoSec Global Inc., 2017
// Basil Hess <basil.hess@infosecglobal.com>
//

/** @file
Arithmetic for Weierstrass curves
*/

#ifndef ISOGENY_REF_WEIER_H
#define ISOGENY_REF_WEIER_H

#include <fp2.h>

struct weier_pt {
  fp2 x;
  fp2 y;
};

/**
 * Represents a point on a (Weierstrass) curve
 */
typedef struct weier_pt weier_pt_t;

struct weier_curve {
  ff_Params *ffData;
  fp2 a;
  fp2 b;
  weier_pt_t P;
  weier_pt_t Q;
};

/**
 * A curve definition with finite-field parameters, coefficients and generator points.
 */
typedef struct weier_curve weier_curve_t;

/**
 * Point multiplication using a double-and-add algorithm
 * @param data Weierstrass curve
 * @param k scalar
 * @param P Point
 * @param Q Result Q = k*P
 * @param msb Most significant bit of `k`
 * @return
 */
int weier_double_and_add(const weier_curve_t *data, const mp k, const weier_pt_t *P, weier_pt_t *Q, int msb);

/**
 * Sets a point to infinity (0, 0)
 * @param data Weierstrass curve
 * @param P point to be set to infinity
 */
void weier_set_inf_affine(const weier_curve_t *data, weier_pt_t *P);

/**
 * Tests a point for infinity
 * @param data Weierstrass curve
 * @param P point to be tested for infinity
 * @return 1 if P equals Inf, 0 if not
 */
int weier_is_inf_affine(const weier_curve_t *data, const weier_pt_t *P);

/**
 * Doubles two affine points on a Weierstrass curve
 * @param data Weierstrass curve
 * @param P point to be doubled
 * @param R result R = 2*P
 * @return
 */
int weier_xDBL(const weier_curve_t *data, const weier_pt_t *P, weier_pt_t *R);

/**
 * Adds two affine points on a Weierstrass curve
 * @param data Weierstrass curve
 * @param P first point
 * @param Q second point
 * @param R result R = P + Q
 * @param tmp Temporary Fp2 elements to be provided externally
 * @return
 */
int weier_xADD(const weier_curve_t *data, const weier_pt_t *P, const weier_pt_t *Q, weier_pt_t *R);

/**
 * Initializes a point
 * @param p Finite field parameters
 * @param pt point to be initialized
 */
void weier_pt_init(const ff_Params* p, weier_pt_t* pt);

/**
 * Clears/frees the memory of a point
 * @param p Finite field parameters
 * @param pt point to be cleared
 */
void weier_pt_clear(const ff_Params* p, weier_pt_t* pt);

/**
 * Initializes a Weierstrass curve
 * @param p Finite field parameters
 * @param curve Curve to be initializes
 */
void weier_curve_init(ff_Params* p, weier_curve_t* curve);

/**
 * Clears/frees the memory held within the Weierstrass curve
 * @param p Finite field parameters
 * @param curve Curve to be cleared
 */
void weier_curve_clear(const ff_Params* p, weier_curve_t* curve);

/**
 * Copies points
 * @param p Finite field parameters
 * @param src Source point
 * @param dst Destination point
 */
void weier_pt_copy(const ff_Params* p, const weier_pt_t* src, weier_pt_t* dst);

/**
 * J-invariant of a Weierstrass curve
 * 1728 * 4A^3 / (4A^3 + 27B^2)
 *
 * @param curve Weierstrass curve
 * @param j_inv Result j-invariant
 */
void weier_j_inv(const weier_curve_t* curve, fp2* j_inv);

#endif //ISOGENY_REF_WEIERSTRASS_H
