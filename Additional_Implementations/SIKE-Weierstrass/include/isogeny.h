//
// SIKE-Weierstrass
//
// InfoSec Global Inc., 2017
// Basil Hess <basil.hess@infosecglobal.com>
//

/** @file
Isogeny functions
*/


#ifndef ISOGENY_REF_WEIER_ISOGENY_H
#define ISOGENY_REF_WEIER_ISOGENY_H

/**
 * Lifts a curve and up to three points to an isogeny, given a kernel point of order 2 or 3.
 *
 * @param E Elliptic curve to be lifted to an isogeny
 * @param ker Kernel point
 * @param P First point to be lifted, may be NULL
 * @param Q Second point to be lifted, may be NULL
 * @param R Third point to be lifted, may be NULL
 * @param EK Image curve E'
 * @param isoP Image point P'
 * @param isoQ Image point Q'
 * @param isoR Image point R'
 */
void
weier_iso_2_3(const weier_curve_t *E,
              const weier_pt_t *ker,
              const weier_pt_t *P,
              const weier_pt_t *Q,
              const weier_pt_t *R,
              weier_curve_t *EK,
              weier_pt_t *isoP,
              weier_pt_t *isoQ,
              weier_pt_t *isoR);


#endif //ISOGENY_REF_WEIER_ISOGENY_H
