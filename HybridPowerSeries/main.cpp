#include <gtest/gtest.h>
#include <Eigen/Dense>
#include <vector>

// Function declarations (assume included from other files)
void computeYZ(Eigen::MatrixXd& Y, Eigen::MatrixXd& Z, const Eigen::MatrixXd& A, const Eigen::MatrixXd& Y0, int N);
void parallelFFT(std::vector<double>& input, std::vector<double>& output, int n);
void solveNonlinear(int N, Eigen::VectorXd& y, const Eigen::VectorXd& v);

TEST(ComputeYZTest, BasicFunctionality) {
    Eigen::MatrixXd A(2, 2), Y(2, 2), Z(2, 2), Y0(2, 2);
    A.setZero();
    Y0.setIdentity();
    computeYZ(Y, Z, A, Y0, 100);
    ASSERT_TRUE(Y.isApprox(Y0, 1e-6));
}

TEST(ParallelFFTTest, BasicFunctionality) {
    int n = 4;
    std::vector<double> input(n, 1.0), output(n);
    parallelFFT(input, output, n);
    // Expected output for constant input (simplified check)
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ASSERT_NEAR(output[i], 4.0, 1e-6); // DC component
        }
        else {
            ASSERT_NEAR(output[i], 0.0, 1e-6); // Other components
        }
    }
}

TEST(SolveNonlinearTest, BasicFunctionality) {
    int N = 100;
    Eigen::VectorXd v(1), y(1);
    v << 0.5;
    solveNonlinear(N, y, v);
    // Expected: y should converge to a fixed point of phi(y) = y(1-y), i.e., y = 0 or y = 1
    ASSERT_TRUE(std::abs(y(0) - 1.0) < 1e-2 || std::abs(y(0) - 0.0) < 1e-2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}