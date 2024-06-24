class Solution{
public:
    int getHeight(Node * node) {
        if (node == NULL) return 0;
        return node -> height;
    }
    
    int getBalance(Node * node) {
        if (node == NULL) return 0;
        return getHeight(node -> left) - getHeight(node -> right);
    }
    
    void updateHeight(Node * node) {
        node -> height = 1 + max(getHeight(node -> left), getHeight(node -> right));
    }
    
    Node * rotateRight(Node * node) {
        Node * leftChild = node -> left;
        Node * leftRightChild = leftChild -> right;
        
        leftChild -> right = node;
        node -> left = leftRightChild;
        
        updateHeight(node);
        updateHeight(leftChild);
        
        return leftChild;
    }
    
    Node * rotateLeft(Node * node) {
        Node * rightChild = node -> right;
        Node * rightLeftChild = rightChild -> left;
        
        rightChild -> left = node;
        node -> right = rightLeftChild;
        
        updateHeight(node);
        updateHeight(rightChild);
        
        return rightChild;
    }
    
    /*You are required to complete this method */
    Node* insertToAVL(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        }
        if (node -> data > data) {
            node -> left = insertToAVL(node -> left, data);
        } else if (node -> data < data) {
            node -> right = insertToAVL(node -> right, data);
        } else {
            return node;
        }
    
        updateHeight(node);
        
        int balance = getBalance(node);
        
        if (balance > 1) {
            if (getBalance(node -> left) < 0) {
                node -> left = rotateLeft(node -> left);
            }
            return rotateRight(node);
        } else if (balance < -1) {
            if (getBalance(node -> right) > 0) {
                node -> right = rotateRight(node -> right);
            }
            
            return rotateLeft(node);
        }
        
        return node;
    }
    
    Node* deleteNode(Node* node, int data)
    {
        if (node == NULL) return node;
        
        if (node -> data > data) {
            node -> left = deleteNode(node -> left, data);
        } else if (node -> data < data) {
            node -> right = deleteNode(node -> right, data);
        } else {
            if (node -> left == NULL || node -> right == NULL) {
                Node * temp = node -> left ? node -> left : node -> right;
                
                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                } else {
                    *node = *temp;
                }
                
                free(temp);
            } else {
                Node * minNode = getMinNode(node -> right);
                
                node -> data = minNode -> data;
                
                node -> right = deleteNode(node -> right, minNode -> data);
            }
        }
        
        if (node == NULL) return node;
        
        updateHeight(node);
        
        int balance = getBalance(node);
        
        if (balance > 1) {
            if (getBalance(node -> left) < 0) {
                node -> left = rotateLeft(node -> left);
            }
            return rotateRight(node);
        } else if (balance < -1) {
            if (getBalance(node -> right) > 0) {
                node -> right = rotateRight(node -> right);
            }
            return rotateLeft(node);
        }
        
        return node;
    }
};