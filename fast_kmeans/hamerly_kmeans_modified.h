#ifndef HAMERLY_KMEANS_MODIFIED_H
#define HAMERLY_KMEANS_MODIFIED_H

/* Authors: Greg Hamerly and Jonathan Drake
 * Feedback: hamerly@cs.baylor.edu
 * See: http://cs.baylor.edu/~hamerly/software/kmeans.php
 * Copyright 2014
 *
 * HamerlyKmeans implements Hamerly's k-means algorithm that uses one lower
 * bound per point.
 */

#include "modified_update_triangle_based_kmeans.h"

class HamerlyKmeansModified : public ModifiedUpdateTriangleBasedKmeans {
    public:
        HamerlyKmeansModified() { numLowerBounds = 1; }
        virtual ~HamerlyKmeansModified() { free(); }
        virtual std::string getName() const { return "hamerlymodified"; }

    protected:
        // Update the upper and lower bounds for the given range of points.
        void update_bounds(int startNdx, int endNdx);

        virtual int runThread(int threadId, int maxIterations);
};

#endif

