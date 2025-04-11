#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>


#include "Student_info.h"
#include "grade.h"
#include "median.h"

using namespace std;

bool did_all_hw(const Student_info& s) {
	return(
		(find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end()
		);
}

double average(const vector<double>& v) {
	//(accumulate = 벡터 시작부터 끝까지 합계) / 크기
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& s) {
	vector<double>grades;

	transform(s.begin(), s.end(), back_inseter(grades), average_grade);

	return median(grades);
}

double grade_aux(const Student_info& s) {
	try {
		return grade(s); //숙제 있르면
	}
	catch(domain)
}

double median_analysis(const vector<Student_info>& s) {
	vector <double> grades;

	transform(s.begin(), s.end(), back_inerter(grades), grade_aux);

	return median(grades);
}

double optimistic_median(const Student_info& s) {
	vector<double>nonzero;

	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
}

double optimistic_median_analysis(
	const vector<Student_info>& s) {
	vector<double> grades;

	transform(s.begin(), s.end(), back_inserter(grades), optimistic_median);

	return median(grades);
}
void write_analysis(
	ostream& out, string& name,
	double analysis(vector<Student_info>&),
	const vector<Student_info>& did, //did
	const vector<Student_info>& didnt //didn't
) {
	out << name << ": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}