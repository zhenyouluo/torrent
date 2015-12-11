#include <walle/ext/xml/rapidxml.hpp>  
#include <walle/ext/xml/rapidxml_utils.hpp> 
#include <walle/ext/xml//rapidxml_print.hpp>  
  

#include<iostream>  
using namespace rapidxml;  
  
int main()  
{  
    file<> fdoc("config.xml");  
    xml_document<> doc;  
    doc.parse<0>(fdoc.data());  
  
    std::string text;    
    rapidxml::print(std::back_inserter(text), doc, 0);    
    std::cout<<text<<std::endl;   
  
    xml_node<>* root = doc.first_node();  
  
    xml_node<>* sec = root->first_node();  
  
    root->remove_node(sec); //�Ƴ����ڵ��µ�sec���(�����ý�������н��)  
    text="ɾ��һ���ڵ�\r\n";    
    rapidxml::print(std::back_inserter(text), doc, 0);    
    std::cout<<text<<std::endl;   
  
    root->remove_all_nodes(); //�Ƴ����ڵ������н��  
    text="ɾ�����нڵ�\r\n";    
    rapidxml::print(std::back_inserter(text), doc, 0);    
    std::cout<<text<<std::endl;   
  
    std::ofstream out("test.xml");  
    out<<doc;  
    system("pause");  
    return 0;  
} 

