#include<iostream>
#include<fstream>
#include <queue>
#include <chrono>
#include<sstream>
#include<cstring>
#include <list>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

///////AVL TREE


struct avlnode {
	string data;
    int height;
    struct avlnode *left;
    struct avlnode *right;
};
class avlTree{
	public:
	struct avlnode* node1;
	avlTree(){
		node1=NULL;
	}
	int find_h(struct avlnode *p){

        if(p->left && p->right){
        if (p->left->height < p->right->height)
            return p->right->height + 1;
        else return  p->left->height + 1;
        }
        else if(p->left && p->right == NULL){
           return p->left->height + 1;
        }
        else if(p->left ==NULL && p->right){
           return p->right->height + 1;
        }
        return 0;

	}
	
	int fun(struct avlnode *n){
            if(n->left && n->right){
                return n->left->height - n->right->height; 
            }
            else if(n->left && n->right == NULL){
                return n->left->height; 
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
    }
    
	struct avlnode* insert(struct avlnode *n1,string data){
	    if(n1==NULL){
	        struct avlnode *n;
	        n = new struct avlnode;
	        n->data = data;
	        n1 = n;
	        n1->left = n1->right = NULL;
	        n1->height = 1; 
	        return n1;             
	    }
	    else{
	        if(data < n1->data)
	        n1->left = insert(n1->left,data);
	        else
	        n1->right = insert(n1->right,data);
	    }
        n1->height = find_h(n1);
        if(fun(n1)==2 && fun(n1->left)==1){
            n1 = llrotation(n1);
        }
        else if(fun(n1)==2 && fun(n1->left)==-1){
            n1 = lrrotation(n1);
        }
		else if(fun(n1)==-2 && fun(n1->right)==-1){
            n1 = rrrotation(n1);
        }
        else if(fun(n1)==-2 && fun(n1->right)==1){
            n1 = rlrotation(n1);
        }
                
    return n1;
    }
            
	struct avlnode* llrotation(struct avlnode *n){
        struct avlnode *temp;
        struct avlnode *temp1;
        temp = n;
        temp1 = temp->left;

        temp->left = temp1->right;
        temp1->right = temp;

        return temp1; 
    }
    struct avlnode* lrrotation(struct avlnode *n){
        struct avlnode *temp;
        struct avlnode *temp1;
        struct avlnode *temp2;
        temp = n;
        temp1 = temp->left;
        temp2 =temp->left->right;
        temp -> left = temp2->right;
        temp1 ->right = temp2->left;
        temp2 ->right = temp;
        temp2->left = temp1; 
        return temp2; 
    }
    struct avlnode* rlrotation(struct avlnode *n){
        struct avlnode *temp;
        struct avlnode *temp1;
        struct avlnode *temp2;
        temp = n;
        temp1 = temp->right;
        temp2 =temp->right->left;

        temp -> right = temp2->left;
        temp1 ->left = temp2->right;
        temp2 ->left = temp;
        temp2->right = temp1; 
        
        return temp2; 
    }
        
  	struct avlnode* rrrotation(struct avlnode *n){
		struct avlnode *temp;
		struct avlnode *temp1;
		temp = n;
		temp1 = temp->right;
		
		temp->right = temp1->left;
		temp1->left = temp;
		
		return temp1; 	
	}
    
	void preorder_traversal(struct avlnode *root)
	{
	    if(root != NULL)
	    {
	        cout << root->data << " ";
	        preorder_traversal(root->left);
	        preorder_traversal(root->right);
	    }
	}
		
	bool search_avl(struct avlnode* root, string key)
	{
	    if (root == NULL)
	        return false;   
	    else if (root->data == key)
	        return true;
	    else if (root->data > key) {
	        bool val = search_avl(root->left, key);
	        return val;
	    }
	  	else {
	        bool val = search_avl(root->right, key);
	        return val;
	    }
	}

};

///BST
class node{
	public:
		string data; 
		node* left;
		node* right;
		node(string d,node* l=NULL,node* r=NULL){
			data=d;
			left=l;
			right=r;
		}
};

class bst_tree{
	public:
	node* head;
		//constructor
		bst_tree(){
			head=NULL;
			
		}
		
	
		void display(node* temp){
			if(temp==NULL){
				return ;
			}
			display(temp->left);
			cout<<temp->data<<" ";
			display(temp->right);
		}
		
		//BST
		void insert(string d){
			if(head==NULL){
				head=new node(d);
			}else{
				node* temp=head;
				while(1){
					if(d<temp->data){
						if(temp->left==NULL){
							temp->left=new node(d);
							break;
						}
						temp=temp->left;
					}
					else{
						if(temp->right==NULL){
							temp->right=new node(d);
							break;
						}
						temp=temp->right;
					}
				}	
			}
		}
		
		//searching the word
		bool search(node* temp,string value){
			if(temp==NULL){
				return false;		
			}
			
			if(temp->data==value){
				
				return true;
			}
		
			if(value<temp->data){
				return search(temp->left,value);
			}
			else if(value>temp->data){
				return search(temp->right,value);
			}
			
			
		}

		//delete the tree 
		void delete_tree(node* temp){
			if(temp==NULL){
				return ;
			}
			delete_tree(temp->left);
			delete_tree(temp->right);
			
			if(temp->left!=NULL){
				temp->left=NULL;
				
			}
			if(temp->right!=NULL){
				temp->right=NULL;
			}
			delete temp;
			temp=NULL; 
		}
	//destructor
		~bst_tree(){
			if(head){
				this->delete_tree(head);
				
			}
		}	
};

///Hash Table

class Hash
{
	int bucket;
	list<string> *hash_table;
	public:
	Hash(){
		
	}	
	Hash(int b)
	{
	    this->bucket = b;
	    hash_table = new list<string>[bucket];
	}
	
	int function(string x) {
    	int sum=0;
    	for(int i=0;i<x.length();i++){
    		sum=sum+(int)x[i];
		}
        return (sum % bucket);
    } 
	void insertion(string key)
	{
	    int index = function(key);
	    hash_table[index].push_back(key);
	}
	bool searching(string key)
	{
	  
		int index = function(key);
		list <string>::iterator i;
		for (i = hash_table[index].begin();i != hash_table[index].end(); i++) {
				if (*i == key){
				return true;
			}
	  }
	  return false;
	}
	void display() {
	  for (int i = 0; i < bucket; i++) {
	    cout << i<<" ";
	    for (string x : hash_table[i])
	      cout<<x;
	    cout << endl;
	  }
	}
};

class WordChecker{
		
	public:	
		void input(string filename,Hash &h){
			string b;
			
			ifstream in(filename+".txt");
			if(in.is_open()){
				while(!in.eof()){
					getline(in,b);
					h.insertion(b); 				
				}	
			}else{
				cout<<"cannot open file "<<endl;
				exit(0);
			}
			
			in.close();
						
		}
		void input(string filename,bst_tree &bst){
			string b;
		
			ifstream in(filename+".txt");
			if(in.is_open()){
				while(!in.eof()){
					getline(in,b);
					bst.insert(b);
					
					 				
				}	
			}else{
				cout<<"cannot open file "<<endl;
				exit(0);
			}
			
			in.close();
						
		}
		void input(string filename,avlTree &avl){
			string b;
			
			ifstream in(filename+".txt");
			if(in.is_open()){
				while(!in.eof()){
					getline(in,b);
					
					avl.node1=avl.insert(avl.node1,b);
								
				}	
			}else{
				cout<<"cannot open file "<<endl;
				exit(0);
			}
			
			in.close();
						
		}
};
	


int main(){
	
	string file_name;
	cout<<"Enter the file name to Load ";
	cin>>file_name;
	
	string search_word;
	cout<<"Enter the word to search ";
	cin>>search_word;
	
	int option=0;
	cout<<"Select the option to use Datastructure"<<endl;
	cout<<"1-> Binary Search Tree"<<endl;
 	cout<<"2-> AVL Tree"<<endl;
	cout<<"3-> Hash Table Tree"<<endl;  
	cin>>option;
	WordChecker obj;
	bool flag=false;

	switch(option){
		case 1:{
			cout<<"option 1 selected "<<endl;
			bst_tree bst;
			
			clock_t start_time = clock();
			obj.input(file_name,bst);
			flag=bst.search(bst.head,search_word);
			clock_t end_time1 = clock();
			clock_t result = end_time1 - start_time;
			cout<<"Time Taken to search "<<result/CLOCKS_PER_SEC<<" seconds"<<endl;
				
			break;
		}
		case 2:{
			
			cout<<"option 2 selected "<<endl;
			avlTree avl;
			clock_t start_time = clock();
			obj.input(file_name,avl);
			flag=avl.search_avl(avl.node1,search_word);
			clock_t end_time1 = clock();
			clock_t result = end_time1 - start_time;
			cout<<"Time taken to search "<<result/CLOCKS_PER_SEC<<" seconds"<<endl;
			
			break;
		}
		case 3:{
		
			cout<<"option 3 selected "<<endl;
			Hash h(200);
			clock_t start_time = clock();
			obj.input(file_name,h);
			flag=h.searching(search_word);
			clock_t end_time1 = clock();
			clock_t result = end_time1 - start_time;
			cout<<"Time taken to search "<<result/CLOCKS_PER_SEC<<" seconds"<<endl;
			break;
		}
		default:
			cout<<"Option not valid";
			break;	
	}
	if(flag){
		cout<<"Word Found";
	}else{
		cout<<"Word Not Found ";
	}	
	  
   
   
   
	return 0;
}
