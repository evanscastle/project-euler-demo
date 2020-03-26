# project-euler-demo

This project was developed as a standalone solution to problem 65 of the Project Euler archives located at https://projecteuler.net/problem=65

## Introduction to Problem

Any real number has a continued fraction expansion which is a sequence of rational approximations formed by repeatedly nesting fractions obtained by reciprocating the fractional part of a real number and taking the integral part. The continued fraction expansion of 'e,' the base of the natural logarithm, is e = [2;1,2,1,1,4,1,1,6,...,1,2k,1,...]. The first few terms in the sequence of convergents for e are: 2, 3, 8/3, 11/4, 19/7, 87/32 ...

## Problem

Find the sum of the digits in the numerator of the 100th convergent of the continued fraction for e

## Solution

The solution has two primary components: an Integer class and an Fraction class. The Integer class implements an arbitrary precision int class to deal with the overflow created when computing the solution. The Fraction class contains a numerator and denominator of Integers and allows for basic arithmetic to be computed using them.

## Current State

A skeleton of the project using ints has been created that works until the overflow issue appears. For the final product, will need to finish developing Integer class including overloading operator methods (+, -, *, /, %, >, <). Fully functional code is contained in main_old.cpp