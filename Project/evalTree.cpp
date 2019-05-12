//#include "stdafx.h"
#include "pch.h"

#include "evalTree.h"

evalTree::evalTree() {
  m_pRoot = nullptr;
}


evalNode* getNodePtr(const char& c) {
    if (c == '*')
      return new evalOp(OC_MUL);
    if (c == '/')
      return new evalOp(OC_DIV);
    if (c == '+')
      return new evalOp(OC_SUM);
    if (c == '-')
      return new evalOp(OC_SUB);
    return new evalConst(c);
};

evalTree::evalTree(std::string &expression) {

  Array<evalNode*> pSymbols(expression.length());
  for (int i = 0; i < pSymbols.Size(); ++i)
    pSymbols[i] = getNodePtr(expression[i]);


  for (int i = 0; i < pSymbols.Size(); ++i)
    if (pSymbols[i]->getSymbol() == '*' || pSymbols[i]->getSymbol() == '/')
      if (!pSymbols[i]->left && !pSymbols[i]->right) {
        pSymbols[i]->left = pSymbols[i - 1];
        pSymbols[i]->right = pSymbols[i + 1];
        pSymbols.deleteElement(i - 1);
        --i;
        pSymbols.deleteElement(i + 1);
      }

  for (int i = 0; i < pSymbols.Size(); ++i)
    if (pSymbols[i]->getSymbol() == '+' || pSymbols[i]->getSymbol() == '-')
      if (!pSymbols[i]->left && !pSymbols[i]->right) {
        pSymbols[i]->left = pSymbols[i - 1];
        pSymbols[i]->right = pSymbols[i + 1];
        pSymbols.deleteElement(i - 1);
        --i;
        pSymbols.deleteElement(i + 1);
      }
  m_pRoot = pSymbols[0];
}

evalTree::~evalTree() { 
  clear(m_pRoot); 
  /*std::cout << "evalTree deleted" << std::endl;*/
}


void evalTree::clear(evalNode *node) {
  if (!node)
    throw std::runtime_error("Bad pointers");
  else {
    if (!node->left && !node->right) {
      delete node;
      return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
  }
}

