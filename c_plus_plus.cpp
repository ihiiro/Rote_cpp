#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// un-named structs
struct {
  int value;
  string a_string;
} struct_one, struct_two; //multiple variables are supported

// named struct
struct ROOM {
  bool has_door, has_window;
};

// functions
void func() {} //void means no return type
int func_int() { return 0; } //returns an int
bool func_bool() { return 1; } //returns bool
// etc...
void swap_nums(int &x, int &y) {
  int z = x;
  x = y;
  y = z;
}

// classes
class MyClass {
public:
  int my_num;
  string my_string;
};

struct ATTRIBUTES_OF_MYCLASS2 {
  int my_num;
  string my_string;
};

class MyClass2 {
public:
  // attributes(functions are called methods)
  int my_num;
  string my_string;
  // constructor method, is called once per object creation
  MyClass2(int x, string y) {
    my_num = x;
    my_string = y;
  }
  ATTRIBUTES_OF_MYCLASS2 return_attributes();
};

ATTRIBUTES_OF_MYCLASS2 MyClass2::return_attributes() {
  ATTRIBUTES_OF_MYCLASS2 attributes;
  attributes.my_num = my_num;
  attributes.my_string = my_string;
  return attributes;
}

class MyClass3 {
private:
  int some_private_attribute = 2;
public:
  int get_private_attribute() {
    return some_private_attribute;
  }
  void set_private_attribute(int value) {
    some_private_attribute = value;
  }
};

// to inherit from multiple classes: public class1, public classN etc...
class MyClass4InheritedFromMyClass3: public MyClass3 {}; //can be public/protected/private

int main() {
  // output to console
  cout << "Hello World!\n";
  cout << "It's me, Yassir!" << endl << endl; // endl is similar to "\n\n"
  cout << "This is in a new line and a new line :)";

  // input to variable
  int num = 0;
  cout << endl << endl;
  cin >> num;
  cout << num;

  // declare variable without definition
  string my_str;

  // multiple variable assignment
  int x = 0, y = 1, z = 2;
  bool assert_x = x == 0;
  bool assert_y = y == 1;
  bool assert_z = z == 2;
  cout << "\n\n" << assert_x << assert_y << assert_z;

  // 1 value to multiple variables
  x = y = z = 0;
  assert_x = x == 0;
  assert_y = y == 1;
  assert_z = z == 2;
  cout << "\n\n" << assert_x << assert_y << assert_z;

  // constant
  const int MY_CONSTANT = 8;

  // ternary operator
  x = 1;
  y = 0;
  // variable = (expression) ? do-if-true : do-if-false
  my_str = (x < y) ? "x < y" : "x >= y";
  cout << endl << endl;
  cout << my_str;

  // for loop
  cout << endl << endl;
  x = 4;
  for (int i = 0; i < x; i++) {
    cout << i << endl;
  }

  // arrays
  int my_array[] = {1, 2, 3, 4};
  int len = sizeof(my_array)/sizeof(my_array[0]);
  cout << endl << endl;
  cout << "Size of my_array is: " << len << endl;
  for (int i = 0; i < len; i++) {
    cout << my_array[i] << endl;
  }

  // create a struct instance of un-named struct
  struct_one.value = 0;
  struct_two.value = 1;
  struct_one.a_string = "hello";
  struct_two.a_string = "bye";
  cout << endl << endl;
  cout << "struct one: value=" << struct_one.value << ", a_string=" << struct_one.a_string << endl;
  cout << "struct two: value=" << struct_two.value << ", a_string=" << struct_two.a_string << endl;

  // create a struct instance of named struct: ROOM
  ROOM my_room;
  my_room.has_door = true;
  my_room.has_window = true;
  cout << endl << endl;
  cout << "my room has window: " << my_room.has_window << ", my room has door: " << my_room.has_door;

  // references
  my_str = "This is epic!";
  string &ref_to_string = my_str;
  cout << endl << endl;
  cout << "ref_to_string=" << ref_to_string << endl;
  cout << "my_str=" << my_str << ", stored in memory address: " << &my_str;

  // pointers
  my_str = "this is a string";
  string* ptr_to_my_str = &my_str;
  cout << endl << endl;
  cout << "my_str=" << my_str << ", stored in memory address: " << &my_str << endl;
  cout << "ptr_to_my_str=" << ptr_to_my_str << endl;
  // dereferencing a pointer
  cout << ptr_to_my_str << " stores value: " << *ptr_to_my_str;
  // modify value via dereferencing
  *ptr_to_my_str = "this is a string{MODIFIED}";
  cout << endl;
  cout << "my_str=" << my_str << ", memory address: " << ptr_to_my_str;

  // pass by reference
  cout << endl << endl;
  x = 10;
  y = 5;
  cout << "prior to swap: x=" << x << ", y=" << y << endl;
  swap_nums(x, y);
  cout << "after swap: x=" << x << ", y=" << y;

  // create object from class
  MyClass my_obj;
  my_obj.my_num = 12;
  my_obj.my_string = to_string(my_obj.my_num);
  cout << endl << endl;
  cout << my_obj.my_num << ", " << my_obj.my_string;

  //
  MyClass2 my_obj2(20, "20");
  ATTRIBUTES_OF_MYCLASS2 attributes;
  attributes = my_obj2.return_attributes();
  cout << endl << endl;
  cout << "(" << my_obj2.my_num << ", " << my_obj2.my_string << ")" << endl;
  cout << "(" << attributes.my_num << ", " << attributes.my_string << ")";

  //
  MyClass3 my_obj3;
  cout << endl << endl;
  cout << "before calling the setter method: " << my_obj3.get_private_attribute() << endl;
  my_obj3.set_private_attribute(3);
  cout << "after calling the setter method: " << my_obj3.get_private_attribute();

  //
  MyClass4InheritedFromMyClass3 my_obj4;

  // I/O with files
  // create/open a file
  ofstream  MyFile("some_file.txt");

  // write to the file
  MyFile << "writing to file now... done";

  MyFile.close();

  // read from file
  string text;
  ifstream MyReadFile("some_file.txt");
  while (getline(MyReadFile, text)) {
    cout << text;
  }

  // close file
  MyReadFile.close();

  // exception handling
  cout << endl << endl;
  try {
    int age = 17;
    if (age >= 18) {
      cout << "access granted.";
    }
    else {
      throw (age);
    }
  }
  catch (int num) {
    cout << "access denied--age must be atleast 18" << endl;
    cout << "age was: " << num;
  }

  return 0;
}
