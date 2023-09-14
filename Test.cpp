/**
 * Tests
 * @author talko
 * @date 01/04/2022.
 */

#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;
using namespace std;

// Vectors
vector<double> vec1 = {1,2,3,4,5,6,7,8,9};
vector<double> vec2 = {6,0,0,0,6,0,0,0,6};
vector<double> vec3 = {3,0,0,0,3,0,0,0,3};
vector<double> vec4 = {9,6,5,8,6,7,9,0,3};
vector<double> vec5 = {2,4,5,5,4,2,2,4,5};
vector<double> zero_vec = {0,0,0,0,0,0,0,0,0};
vector<double> empty_vec = {};

// Matrices
Matrix m1(vec1, 3, 3);
Matrix m2(vec2, 3, 3);
Matrix m3(vec3, 3, 3);
Matrix m4(vec4, 3, 3);
Matrix m5(vec5, 3, 3);
Matrix zero_mat(zero_vec, 3, 3);


TEST_CASE("1. Check Input") {
    CHECK_THROWS(Matrix a(vec1, -3, 3));
    CHECK_THROWS(Matrix a(vec1, 3, -3));
    CHECK_THROWS(Matrix a(vec1, -3, -3));
    CHECK_THROWS(Matrix a(vec1, 0, 3));
    CHECK_THROWS(Matrix a(vec1, 3, 0));
    CHECK_THROWS(Matrix a(vec1, 0, 0));
    CHECK_THROWS(Matrix a(empty_vec, 3, 3));
}

TEST_CASE("2. Calculation On Matrix"){
    SUBCASE("Increase"){
        ++m1;
        for (unsigned long i = 0; i < vec1.size(); ++i) {
            CHECK_EQ((m1.data[i]-vec1[i]),1);
        }

        ++m2;
        for (unsigned long i = 0; i < vec2.size(); ++i) {
                    CHECK_EQ((m2.data[i]-vec2[i]),1);
        }

        ++m3;
        for (unsigned long i = 0; i < vec3.size(); ++i) {
                    CHECK_EQ((m3.data[i]-vec3[i]),1);
        }

        ++m4;
        for (unsigned long i = 0; i < vec4.size(); ++i) {
                    CHECK_EQ((m4.data[i]-vec4[i]),1);
        }

        ++zero_mat;
        for (unsigned long i = 0; i < zero_vec.size(); ++i) {
                    CHECK_EQ((zero_mat.data[i]-zero_vec[i]),1);
        }
    }

    SUBCASE("Reduce"){
        --m1;
        for (unsigned long i = 0; i < vec1.size(); ++i) {
                    CHECK_EQ((vec1[i] - m1.data[i]),1);
        }

        --m2;
        for (unsigned long i = 0; i < vec2.size(); ++i) {
                    CHECK_EQ((vec2[i] - m2.data[i]),1);
        }

        --m3;
        for (unsigned long i = 0; i < vec3.size(); ++i) {
                    CHECK_EQ((vec3[i] - m3.data[i]),1);
        }

        --m4;
        for (unsigned long i = 0; i < vec4.size(); ++i) {
                    CHECK_EQ((vec4[i] - m4.data[i]),1);
        }

        --zero_mat;
        for (unsigned long i = 0; i < zero_vec.size(); ++i) {
                    CHECK_EQ((zero_vec[i] - zero_mat.data[i]),1);
        }
    }

    SUBCASE("Multiply By Scalar"){
        Matrix res1 = (m1*2);
        for (unsigned long i = 0; i < vec1.size(); ++i) {
                    CHECK_EQ(vec1[i] / res1.data[i],2);
        }

        Matrix res2 = (m2*3); // V
        for (unsigned long i = 0; i < vec2.size(); ++i) {
                    CHECK_EQ(vec2[i] / res2.data[i],3);
        }

        Matrix res3 = (m3*4); // V
        for (unsigned long i = 0; i < vec3.size(); ++i) {
                    CHECK_EQ(vec3[i] / res3.data[i],4);
        }

        Matrix res4 = (m4*5); // V
        for (unsigned long i = 0; i < vec4.size(); ++i) {
                    CHECK_EQ(vec4[i] / res4.data[i],5);
        }
    }
}

TEST_CASE("3. Calculation On 2 Matrices"){
    SUBCASE("Plus"){
        Matrix res4 = (m4+zero_mat);
        for (unsigned long i = 0; i < vec4.size(); ++i) {
                    CHECK_EQ(res4.data[i],vec4[i]);
        }

        Matrix res3 = (m3+m1);
        for (unsigned long i = 0; i < vec3.size(); ++i) {
                    CHECK_EQ(res3.data[i] + vec1[i],res3.data[i] + i + 1);
        }
    }

    SUBCASE("Minus"){
        Matrix res4 = (m4-zero_mat);
        for (unsigned long i = 0; i < vec4.size(); ++i) {
                    CHECK_EQ(res4.data[i],vec4[i]);
        }

        Matrix res3 = (m3-m1);
        for (unsigned long i = 0; i < vec3.size(); ++i) {
                    CHECK_EQ(res3.data[i] - vec1[i],res3.data[i]-(i+1));
        }
    }

    SUBCASE("Multiply"){
        Matrix res1 = (m1*zero_mat);
        for (unsigned long i = 0; i < vec1.size(); ++i) {
                    CHECK_EQ(res1.data[i],0);
        }

        Matrix res4 = (m4*zero_mat);
        for (unsigned long i = 0; i < vec4.size(); ++i) {
                    CHECK_EQ(res4.data[i],0);
        }
    }
}

TEST_CASE("5. Comparing Calculations") {
    SUBCASE("Greater"){
        CHECK_EQ(m2>m3,true);
        CHECK_NE(m2<m3,true);
        CHECK_EQ(zero_mat<m1,true);
        Matrix res6 = zero_mat+m3;
        CHECK_NE(res6 > m2,true);
        CHECK_EQ(m1>m2, true);
    }

    SUBCASE("Lower"){
        CHECK_EQ(m2>m3,true);
        CHECK_NE(m2<m3,true);
        CHECK_EQ(zero_mat<m1,true);
        CHECK_NE(m1<m2, true);
        Matrix res5 = zero_mat+m3;
        CHECK_EQ(res5 < m2,true);
    }

    SUBCASE("Equals"){
        CHECK_EQ((m2==m2),true);
        CHECK_NE((m2==m3),true);
        Matrix res3 = zero_mat+m3;
        CHECK_EQ((m3==res3),true);
        Matrix res4 = m2-m3;
        CHECK_EQ((res4==m3), true);
    }

    SUBCASE("Not Equals"){
        CHECK_EQ(m2 != m3,true);
        CHECK_NE(m2 != m2,true);
        CHECK_EQ(m1 != zero_mat, true);
        Matrix res1 = m2-m3;
        CHECK_NE(res1 != m3,true);
    }
}