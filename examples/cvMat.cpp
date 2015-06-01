#include <iostream>
#include <opencv2/core/core.hpp>

int main() {

    double data[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    cv::Mat m = cv::Mat(3, 3, CV_64F, data);
    std::cout << "m = "<< std::endl << " "  << m << std::endl << std::endl;

    cv::Mat m_repeat = cv::repeat(m, 3, 3);
    std::cout << "m_repeat = "<< std::endl << " "  << m_repeat << std::endl << std::endl;

    cv::Mat m_expanded = cv::Mat::zeros(9, 9, CV_64F);
    for (int row = 0; row < m.rows; row++)
    {
        for (int col = 0; col < m.cols; col++)
        {
            m_expanded(cv::Range(row*3,(row+1)*3), cv::Range(col*3,(col+1)*3)) = m.at<double>(row, col);
        }
    }
    std::cout << "m_expanded = "<< std::endl << " "  << m_expanded << std::endl << std::endl;

    m_expanded.t();  // this does not transpose in place, but only creates temporary object.
    std::cout << "m_expanded = "<< std::endl << " "  << m_expanded << std::endl << std::endl;

    cv::Mat vect1D = cv::Mat(9, 1, CV_64F, data);
    std::cout << "vect1D = "<< std::endl << " "  << vect1D << std::endl << std::endl;

    return 1;
}
