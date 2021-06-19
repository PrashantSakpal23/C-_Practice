#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/**********************************************************************/
/* UDF definitions */
/**********************************************************************/

std::string read_file_into_string()
{
	std::ifstream ifile("/home/prashant/study/cpp/sstream/ostringstream.cpp");
	
	std::ostringstream buf;	/* It grows as needed */
	char ch;

	/* Read file char by char */
	while(buf && ifile.get(ch))
	{
		buf.put(ch);
//		std::cout << "*";
	}
//	std::cout << std::endl << "File read complete" << std::endl;
	return buf.str();
}

/**********************************************************************/
/* main function */
/**********************************************************************/

int main()
{
	std::string text = read_file_into_string();

	std::cout << text << std::endl;

/*

	std::vector<std::string::size_type>lines_of_text;
	std::string::size_type pos = 0;

	while(pos != std::string::npos)
	{
		pos = text.find('\n',pos);
		lines_of_text.push_back(pos);
	}

*/

	/* Output File code */

	std::filebuf fb;
	fb.open("/home/prashant/study/cpp/sstream/output.txt", std::ios::out);

	std::ostream os(&fb);

	os << text;

	fb.close();
	
	return(0);	
}
