//#include "stdafx.h"
#include "pch.h"

#include <stdexcpt.h>
#include <iostream>

//#include "objects.h"
#include "Architect.h"

//#include "hasht.h"
//#include "AVLtree.h"
//include "RBtree.h"

//#include "bitio.h" 
#include <fstream> 
//#include "huff.h" 

#include <string> 
//#include "evalTree.h"

#include "stakk.h"
#include "qu.h"
#include "formula.h"


using namespace std;

/*
class SampleOne {
public:
  int generateID() { return 0; };
  static SampleOne* getSampleOne() {
    if (_one == nullptr) _one = new SampleOne();
    return _one;
  }
private:
  SampleOne() {};
  static SampleOne *_one;

};

SampleOne *SampleOne::_one = nullptr;

bool testArchitectAddQuantity() {
  Architect ar;
  Id id = ar.addElement(1, 1);
  Array<Id> ids = ar.getALLIds();
  if (ids.Size() != 1) return false;
  if (ids[0] != id) return false;
  id = ar.addElement(1, 1);
  ids = ar.getALLIds();
  if (ids.Size() != 2) return false;

  return true;
}

bool testArchitectAddType() {
  Architect ar;
  Id id = ar.addElement(1, 1);
  Array<Id> ids = ar.getALLIds();
  if (ar.getObjTypeById(id) != FI_POINT) 
    return false;
  return true;
}*/

class Base {
public:
  Base(int a) :m_a(a) {}
  ~Base() { cout << "Base object killed having a = " << m_a << endl; }
  operator int() { return m_a; }
  //private:
protected:
  int m_a;
};

class Sub : private Base {
public:
  Sub(int a ) : Base(a) {}
  virtual ~Sub() { cout << "Sub object killed with a = " << m_a << endl; }
  virtual void say() { cout << "Hello " << m_a + 2 << endl; }
};

class SubSup : public Sub {
public:
  SubSup(int a): Sub(a) {}
  ~SubSup() { cout << "Oh no! SubSup is killed! " << endl; }
  void write() { 
    cout << "Hello! I'm supreme!  " << 2 << endl; 
  }
  void say() {
    cout << "Hello! SupSub there  " << 2 << endl;
  }
};

Array<Sub*> giveMePleaseObjects() {
  Array<Sub*> objs(2);
  objs.changeValue(0, new Sub(45));
  objs.changeValue(1, new SubSup(34));
  return objs;
}


int main() {

 /* 
  Sub s(45);
  Sub* psub = &s;
  psub->say();


  SubSup ss(34);
  psub = &ss;
 */

  /*
  Array<Sub*> objs = giveMePleaseObjects();

  for (int i = 0; i < objs.Size(); ++i)
    objs[i]->say();

  cout << "Clear all objects \n" << endl;

  for (int i = 0; i < objs.Size(); ++i)
    delete objs[i];
 */

  /*try {
    evalTree tree;
    cout << tree.eval() << endl;
    tree.getUsualForm();
    cout << endl;
 }
  catch (runtime_error r) {
    cout << r.what() << endl;
  }*/

  /*
  string expression = "3+5*2-4/2";
  try {
    evalTree tree(expression);
    cout << tree.evalChar() << endl;
  }
  catch (runtime_error r) {
    cout << r.what() << endl;
  }
  catch (invalid_argument er) {
    cout << er.what() << endl;
  }
  */


  //int c = '3' - '0';

  /*!!!
  while (1) {
    stakk<int> queue;
    for (int i = 0; i < 3; ++i)
      queue.push(i);
  }
  */

  char f[] = "(((5+7)*(2+2*2))/(((4/2)*4)+2*2))/6";   //((6+10-4)*5)/(1+1*2)+1
  qu<FormulaNode> inputQ, outputQ;

  FormulaParser< qu<FormulaNode> > parser;
  parser.setResult(&outputQ);
  parser.parse(f);
  

  outputQ.print();

  try {
    DijkstraSorter< qu<FormulaNode> > result;
    result.setInput(&outputQ);
    result.setOutput(&inputQ);

    result.run();

    cout << evaluate(inputQ) << endl;
   
  }
  catch (logic_error r1) {
    cout << r1.what() << endl;
  }
  catch (runtime_error r2) {
    cout << r2.what() << endl;
  }

  
  



  /*
  Array<bool> ar;
  bool b = true;
  ar.setValue(0, b);



  try {
    fstream ifs("data.in");
    Array <para<unsigned char, size_t> > symbols_w_freqs = calcStats(ifs);
    HuffNode* root = buildHuffTree(symbols_w_freqs);
    AVLtree <unsigned char, Array<bool> >  tablE = tree2table(root);

    ifs.clear();
    ifs.seekg(0);

    
    ofstream fs("data.out");
    bitwriter <ofstream> bw(&fs);

    while (ifs) {
      unsigned char byt = ifs.get();
      Array <bool> &huffcode = tablE[byt];
      for (int k = 0; k < huffcode.Size(); ++k)
        bw.writebit(huffcode[k]);
    }
  }
  catch(invalid_argument &e) {
    cout << e.what() << endl;
  }



  AVLtree <int, double> b;


  
  hasht< int, double, double> ha_point;
  hasht< int, double, double > ha_section;
  hasht< int, double, double> ha_arc;

  for (int k = 0; k < 300; ++k)
    try {
    ha_point.AddData(k,2.5);
    }
  catch(int) {
    cout << "Problem at " << k << endl;
  }

  ha_point.AddData(2, 2.6);
  ha_point.hasK(2);/*

  BMPRenderer renderer("sample.bmp");
  for (int k = 0; k < 100; ++k)
    renderer.draw(k, 4);

  Architect ar;
  ar.addElement(4, 5.6);
  ar.addElement(4, 5.6, 3, 5.4);
  ar.addElement(4, 5.6, 3, 5.4, 2.5);
  point2 p;
  p.id = 12;

  list<int> l1(1);
  list<int> l2(2);
  list<int> l3(3);
  l1 = l2 = l3;
  list<int>::Pointer p1(l1);
  list<int>::Pointer p2(l2);

  cout << *p1 << " " << *p2 << endl;*/


  return 0;
}