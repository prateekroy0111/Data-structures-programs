#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
};

struct tnode *CreateBST(struct tnode *, int);
void Inorder(struct tnode *);
void Preorder(struct tnode *);
void Postorder(struct tnode *);

struct tnode *CreateBST(struct tnode *root, int item)
{
    if(root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if(item < root->data )
            root->left = CreateBST(root->left,item);
        else if(item > root->data )
            root->right = CreateBST(root->right,item);
        else
            printf(" Duplicate Element !! Not Allowed !!!");

        return(root);
    }
}

void Inorder(struct tnode *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->data);
        Inorder(root->right);
    }
}

void Preorder(struct tnode *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct tnode *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->data);
    }
}

int Countallnode(struct tnode *root)
{
    if( root == NULL)
    	return 0;
    else
		return ( Countallnode(root->left)+1+Countallnode(root->right) );
}

void Displayleaf(struct tnode *root)
{
    if( root != NULL)
    {
        Displayleaf(root->left);
        if( (root->left==NULL) && (root->right==NULL))
        	printf(" %d ",root->data);
        Displayleaf(root->right);
    }
}

int main()
{
    struct tnode *root = NULL;
    int choice, item, n;
    do
    {
        printf("\n\nBinary Search Tree Operations\n");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Count All Nodes");
        printf("\n6. Display Leaf nodes");
        printf("\n7. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        	case 1:
        		{
        			printf("\nEnter data for node : ");
		            scanf("%d",&item);
		            root = CreateBST(root,item);
				}
            	break;
	        case 2:
	        	{
	        		printf("\nBST Traversal in INORDER \n");
	            	Inorder(root);
				}
	            break;
	        case 3:
	        	{
	        		printf("\nBST Traversal in PREORDER \n");
	            	Preorder(root);
				}
	            break;
	        case 4:
	        	{
	        		printf("\nBST Traversal in POSTORDER \n");
	            	Postorder(root);
				}
	            break;
	        case 5:
	        	{
	        		printf("\nBST Count All Nodes \n");
	        		int total=Countallnode(root);
	        		printf("\nBST Total Nodes = %d \n",total);
	            	
				}
	            break;
	        case 6:
	        	{
	        		printf("\nLeaf Nodes \n");
	            	Displayleaf(root);
				}
	            break;
	        case 7:
	            exit(0);
	            break;
	        default:
	            printf("\n\nInvalid Option !!! Try Again !! \n\n");
        }
    } while(choice != 7);
    
    return 0;
}
