#include <string>  
#include <iostream>  
#include <fstream>  
#include <walle/ext/xml/rapidxml.hpp>  
#include <walle/ext/xml/rapidxml_utils.hpp> 
#include <walle/ext/xml//rapidxml_print.hpp>  

  
  
using namespace rapidxml;  
using namespace std;  
  
int main()  
{  
  
    xml_document<> doc; //�ǽ�����  
    char a[] = "<top>"//���������, �Ͳ��ܼ���xml��ͷ����Ϣ��  
               //����ᱨ��  
               "<name>tangqiang</name>"  
               "<age>22</age>"  
               "</top>";  
    char* p = a;  
    doc.parse<0>(p);  
  
    xml_node<>* node = doc.first_node();//ȥ�������  
    cout << (node->name())<< endl;  
    node = node->first_node();  
    while (node) {  
        cout << node->name() << node->value() << endl;//name() value()���ص��ַ�������ȥ����β�Ŀհ��ַ�  
        node = node->next_sibling();  
    }  
  
    ofstream out("test.xml");//ofstream Ĭ��ʱ������ļ�������Ḳ��ԭ�������ݣ�����������½�  
    out << doc;//doc �������ʱ��Ŀ���ļ��в�����xml ͷ��Ϣ---<?xml version='1.0' encoding='utf-8' >  
    out.close();  
    return 0;  
}  

