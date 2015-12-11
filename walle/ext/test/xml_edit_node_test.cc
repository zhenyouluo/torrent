#include <walle/ext/xml/rapidxml.hpp>  
#include <walle/ext/xml/rapidxml_utils.hpp> 
#include <walle/ext/xml//rapidxml_print.hpp>  

  
#include<iostream>  
using namespace rapidxml;  
  
int main()  
{  
    file<> fdoc("config.xml");  
    std::cout<<fdoc.data()<<std::endl;  
    xml_document<> doc;  
    doc.parse<0>(fdoc.data());  
  
    std::cout<<doc.name()<<std::endl;  
  
    //! ��ȡ���ڵ�  
    xml_node<>* root = doc.first_node();  
    xml_node<>* delnode = root->first_node("color");  
    root->remove_node(delnode);//��ɾ��address�ڵ�  
    //  
    xml_node<>* lnode = root->first_node("size");//�ҵ�post�ڵ�  
    xml_node<>* mynode=doc.allocate_node(node_element,"address","�ӱ�");  
    root->insert_node(lnode,mynode);  
  
    std::string text;  
    rapidxml::print(std::back_inserter(text),doc,0);  
  
  
    std::cout<<text<<std::endl;  
  
    std::ofstream out("version.xml");  
    out << doc;  
    return 0;     
} 

