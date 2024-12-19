
#include <string>
#include "IRecord.h"
using namespace std;

bool IRecord::Save() {
	return false;
}
bool IRecord::Delete() {
	return false;
}
string IRecord::ToReport() {
	return "No Report Configured.";
}