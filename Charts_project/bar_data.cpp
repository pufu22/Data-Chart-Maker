#include "bar_data.h"
#include<string>
Bar_data::Bar_data(std::vector<std::vector<int>> m_sets, std::string m_title, std::list<std::string> m_categories, int m_range[]):sets(m_sets),title(m_title),
    categories(m_categories){};


Bar_data::Bar_data():sets({{3},{1}}),title("riempi"),categories({"w ","e"}),range({-10,15}){};

//int const Bar_data::numero_categorie(){
//    int count=0;
//    for(unsigned int i=0;i<categories.size();++i){
//        count++;
//    }
//    return count;
//};
//int const Bar_data::numero_set(){
//    int count=0;
//    for(unsigned int i=0;i<sets.size();++i){
//        count++;
//    }
//    return count;
//}
