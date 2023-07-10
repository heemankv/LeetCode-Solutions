
class Node {
public:
    int key;
    int val;
    Node* left;
    Node* right;

    Node(int _key, int _val){
        key = _key;
        val = _val;
    }
};


class LRUCache {
private:
    int capacity;
    // mapper -> key -> addr
    unordered_map<int,Node*> mapper;
    // making head and tail for DLL
    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        // initially nothing so head points to tail 
        head -> right = tail;
        // and tail points to head
        tail -> left = head;
    }

    // TODO : complete these
    void addNodetoFront(Node* node){
        Node* currFront = head->right;
        head->right = node;
        node->left = head;
        node->right = currFront;
        currFront->left = node;
    }

    void deleteNode(Node* node){
        Node* leftExtra = node->left;
        Node* rightExtra = node->right;
        leftExtra->right = rightExtra;
        rightExtra->left = leftExtra;
    }
    
    int get(int _key) {
        bool keyAlreadyPresent = mapper.find(_key) != mapper.end();
        if(keyAlreadyPresent){
            Node* res = mapper[_key];
            mapper.erase(_key);
            deleteNode(res);
            addNodetoFront(res);
            mapper[_key] = head->right;
            return res->val;
        }
        // if key is not present return it;
        return -1;
    }
    

    void put(int _key, int _value) {
        bool keyAlreadyPresent = mapper.find(_key) != mapper.end();

        // if key is already present then delete it's reference then it's node
        if(keyAlreadyPresent){
            Node * currVal = mapper[_key];
            mapper.erase(_key);
            deleteNode(currVal);
        }

        bool isFull = mapper.size() == capacity;
        // is say the size is filled, then remove the tail node
        if (isFull) {
            mapper.erase(tail -> left -> key);
            deleteNode(tail -> left);
        }

        // finally put the new node at the start
        // add to DLL then to map
        addNodetoFront(new Node(_key, _value));
        mapper[_key] = head->right;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
