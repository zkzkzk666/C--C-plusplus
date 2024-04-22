// 插入链表节点的函数
Node *insertNode(Node *head, int height)
{
    Node *newNode = new Node(); // 创建新节点
    newNode->height = height;
    newNode->next = nullptr;

    // 处理链表为空的情况
    if (head == nullptr)
    {
        head = newNode;
        return head;
    }

    // 处理新节点比头节点小的情况
    if (height < head->height)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // 找到合适的位置插入节点
    Node *current = head;
    while (current->next != nullptr && current->next->height < height)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}