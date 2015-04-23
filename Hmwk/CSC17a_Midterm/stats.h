/* 
 * File:   stats.h
 * Author: Tri Le
 *
 * Created on April 10, 2015, 6:13 PM
 */

#ifndef STATS_H
#define	STATS_H

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

#endif	/* STATS_H */

