#pragma once

#include "qu.h"
#include "stakk.h"


class FormulaNode {
public:
  FormulaNode() {
    m_number = 0;
    m_oper = 0;
    m_isOperator = false;
  }
  
  FormulaNode(char c) {
    m_number = 0;
    m_oper = c;
    m_isOperator = true;
  }

  FormulaNode(double d) {
    m_number = d;
    m_oper = 0;
    m_isOperator = false;
  }

  bool isOperator()const {
    return m_isOperator;
  }

  bool isOperand()const {
    return m_isOperator;
  }

  void print() {
    if (!m_isOperator)
      cout << m_number << " ";
    else
      cout << m_oper << " ";
  }

  double value()const {
    if (!m_isOperator)
      return m_number;
    else throw std::logic_error("It's not a number");
  }

  void setOp(Operators c) {
    switch (c) {
    case SUM: m_oper = '+'; break;
    case SUB: m_oper = '-'; break;
    case MUL: m_oper = '*'; break;
    case DIV: m_oper = '/'; break;
    case OPEN_BRACKET: m_oper = '('; break;
    case CLOSE_BRACKET: m_oper = ')'; break;
    }
  }

private:
  double m_number;
  char m_oper;
  bool m_isOperator;
};


template<typename Q> class FormulaParser {
public:
  void setResult(Q *q) {
    m_qu = q;
  }

  void parse(const char* formula) {
    for (int i = 0; i < formula.size(); ++i) {
      double ch = 0;
      if (formula[i] >= 48 && formula[i] <= 57) {
        ch = ch * 10;
        ch += formula[i] - '0';
      }
      int counter = 0;
      if (formula[i] == ',') {
        ++i;
        while (formula[i] != '+' || formula[i] != '-' || formula[i] != '*' || formula[i] != '/') {
          counter--;
          ch += (formula[i] - '0') * pow(10, counter);
        }
      }
      FormulaNode node;
      if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == ')' || formula[i] == '(')
        FormulaNode node(formula[i]);
      else
        FormulaNode node(ch);
      m_qu.push(node);
    }
  }

private:
  Q * m_qu;
};


template<typename Q> class DijkstraSorter {
  void setInput(Q*) {
    m_qu = Q;
  }
  void setOutput(Q*) {
    
  }
  void run() {

  }
private:
  Q* m_qu;
  stakk<Operators> m_stack;
};


template<typename Q>  double evaluate(Q&q) {
  while (!q.empty()) {
    
  }
};


Operators Compare(const Operators& op1, const Operators& op2) {
  if (op1 == DIV || op1 == MUL)
      return op1;
  if (op1 == SUM || op1 == SUB)
    if (op2 == DIV || op2 == MUL)
      return op2;
    else
      return op1;
}


void fromBaseToPost(string str) {
  stakk<Operators> stack;
  qu<FormulaNode> queue;
  for (int i = 0; i < str.size(); ++i) {
    double ch = 0;
    if (str[i] >= 48 && str[i] <= 57) {
      ch = ch * 10;
      ch += str[i] - '0';
    }
    int counter = 0;
    if (str[i] == ',') {
      ++i;
      while (str[i] != '+' || str[i] != '-' || str[i] != '*' || str[i] != '/') {
        counter--;
        ch += (str[i] - '0') * pow(10, counter);
      }
    }
    FormulaNode o(ch);
    queue.push(o);
    if (str[i] != '+' || str[i] != '-' || str[i] != '*' || str[i] != '/' || str[i] == '(' || str[i] == ')') {
      if (stack.empty())
        switch (str[i]) {
        case'+':
          stack.push(SUM);
        case'-':
          stack.push(SUB);
        case'*':
          stack.push(MUL);
        case'/':
          stack.push(DIV);
        case'(':
          stack.push(OPEN_BRACKET);
        }
      else {
        switch (str[i]) {
        case'+':
          if (Compare(SUM, stack.looktop()))
            stack.push(SUM);
          else
            while (!stack.empty()) {
              FormulaNode o;
              o.setOp(stack.looktop());
              queue.push(o);
              stack.pop();
            }
        case'-':
          if (Compare(SUB, stack.looktop()))
            stack.push(SUB);
          else
            while (!stack.empty()) {
              FormulaNode o;
              o.setOp(stack.looktop());
              queue.push(o);
              stack.pop();
            }
        case'*':
          if (Compare(MUL, stack.looktop()))
            stack.push(MUL);
        case'/':
          if (Compare(MUL, stack.looktop()))
            stack.push(DIV);
        case'(':
          stack.push(OPEN_BRACKET);
        case')':
          while (stack.looktop() != ')') {
            FormulaNode o;
            o.setOp(stack.looktop());
            queue.push(o);
            stack.pop();
          }
          stack.pop();
        }
      }
    }
  }
  while (!stack.empty()) {
    FormulaNode o;
    o.setOp(stack.looktop());
    queue.push(o);
    stack.pop();
  }
  while (!queue.empty()) {
    FormulaNode node = queue.getfirst();
    node.print();
  }
}