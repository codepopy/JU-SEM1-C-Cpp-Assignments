#include<iostream>
using namespace std;
class Number_List{
	private:
		int *arr;
		int size;
	public:
		void createArray(){
			
			cout<<"please enter the size : ";
			cin>>size;
			arr = new int[size];
			
			cout<<"please enter the values for the array : "<<endl;
			for(int i =0;i<size;i++){
				cin>>arr[i];
			}
		}
		
		void sortAndFind(){
			
			for(int i =0;i<size-1;i++){
				for(int j=0;j<size-i-1;j++){
					
					if(arr[j]>arr[j+1]){
						int temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
						
				}
			}
			
			cout<<"the largest element is : "<<arr[size-1]<<endl;
			cout<<"the smallest element is : "<<arr[0]<<endl;
		}
		
		void print(){
			for( int i =0; i<size;i++){
				cout<<arr[i]<<", ";
			}
		}
		
};

int main(){
	
	Number_List a;
	a.createArray();
	a.sortAndFind();
	a.print();
	
	return 0;
}
