
all: a.out

clean: 
	rm -f a.out *.o

a.out : Student.o StudentArray.o CourseArray.o Course.o Enrollment.o EnrollmentArray.o main.cpp
	g++ main.cpp Student.o StudentArray.o CourseArray.o Course.o Enrollment.o EnrollmentArray.o

Student.o: Student.h Student.cpp
	g++ -c Student.cpp
StudentArray.o: StudentArray.h StudentArray.cpp
	g++ -c StudentArray.cpp
Course.o: Course.h Course.cpp
	g++ -c Course.cpp
CourseArray.o: CourseArray.h CourseArray.cpp
	g++ -c CourseArray.cpp
Enrollment.o: Enrollment.h Enrollment.cpp
	g++ -c Enrollment.cpp
EnrollmentArray.o: EnrollmentArray.h EnrollmentArray.cpp
	g++ -c EnrollmentArray.cpp
