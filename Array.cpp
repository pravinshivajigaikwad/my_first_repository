#include <iostream>
#include <array>
#include <algorithm>
struct Mystruct
{
	int start,end;
};
bool compareStruct(struct Mystruct  a,struct Mystruct b)
{
	return a.start>b.start;
}
bool compareInt(int a,int b)
{
	return a>b;
}
int main()
{
	Mystruct structArray[]={{10,25},{36,90},{5,6},{12,35},{30,52}};
	int array[]={1,2,3,0,0,5,0,2,1,4};
	int len=sizeof(array)/sizeof(array[0]);
	//std::sort(array,array+len,compareInt);
	std::sort(array,array+len,[](auto a,auto b){return a<b;});
	for(auto & elm:array)
	{
		std::cout<<" "<<elm;
	}std::cout<<std::endl;

	len=sizeof(structArray)/sizeof(structArray[0]);
	//std::sort(structArray,structArray+len,compareStruct);
	std::sort(structArray,structArray+len,[](auto a,auto b){return a.start<b.start;});
	for(auto & elm:structArray)
	{
		std::cout<<" "<<elm.start<<":"<<elm.end;
	}std::cout<<std::endl;

	std::array<int,10> ary={25,11,36,69,8,40,22,4,33,44};
	for(auto & elm:ary)
	{
		std::cout<<" "<<elm;
	}std::cout<<std::endl;
	auto it=ary.begin();
	while(it!=ary.end())
	{	
		std::cout<<" "<<*it;
		it++;
	}std::cout<<std::endl;
	std::sort(ary.begin(),ary.end(),[](auto a,auto b){return a>b;});
	std::for_each(ary.begin(),ary.end(),[](const int& elm)
	{
		std::cout<<" "<<elm;
	});
	std::cout<<std::endl;
	std::cout<<"Array Size:"<<ary.size()<<std::endl;

	std::array<Mystruct,5> aryStruct={structArray[0],structArray[1],structArray[2],structArray[3],structArray[4]};
	std::sort(aryStruct.begin(),aryStruct.end(),[](auto& a,auto& b){return a.end>b.end;});
	std::for_each(aryStruct.begin(),aryStruct.end(),[](auto& elm)
	{
		std::cout<<" s:"<<elm.start<<" e:"<<elm.end<<std::endl;
	});
	return 0;
}
