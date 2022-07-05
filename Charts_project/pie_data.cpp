#include "pie_data.h"
#include<QVariantList>
pie_data::pie_data():etichette({"John","Jude","Eunbi"}),title("Persone che occupano gli stock di holo"),valori({1,32,12})
{

}

pie_data::pie_data(std::vector<int> s1, std::vector<std::string> s2, std::string s3):etichette(s2),title(s3),valori(s1){}

pie_data& pie_data::operator =(const pie_data& other)
{
    if (this == &other)
            return *this;
    this->etichette=other.etichette;
    this->valori=other.valori;
    this->title=other.title;
    return *this;
}
