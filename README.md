# CS303_Assignment3
Infix to Postfix conversion and Queue implentation
This Program consist of two parts. One is an Infix to Postfix conversion. The other sets up a Queue using a singly linked list.
The main menu is as follows:

![image](https://user-images.githubusercontent.com/55415231/232656279-10dda6b5-33e5-4fb4-9af4-a7e6cf1bae6b.png)

To start, let's start Part 1. We'll add a formula. Operators to be considered are +, –, *, /, %.

![image](https://user-images.githubusercontent.com/55415231/232656623-4853f250-2feb-4627-b74e-4ae435536649.png)

If we are to enter an equation that does not have a closing parenthesis, then we will get an error:

![image](https://user-images.githubusercontent.com/55415231/232658278-1f38062e-11e5-4511-a134-c3dc3d725d64.png)

Similarly, if we do not have an opening bracket, an error will also be thrown. Position starts from zero.

![image](https://user-images.githubusercontent.com/55415231/232658485-76785661-f14b-4d81-b3a1-fab056438c39.png)

For part 2, we have a Queue using a singly linked list. First we'll check to make sure it is empty to start:

![image](https://user-images.githubusercontent.com/55415231/232656805-e3a459bd-7bed-4783-a855-15cc009a7d23.png)

Next we'll add a number:

![image](https://user-images.githubusercontent.com/55415231/232656902-3093096d-3a83-4feb-a78e-4d9af814213a.png)

Confirming it is there:

![image](https://user-images.githubusercontent.com/55415231/232656947-566e1cd9-f6aa-4945-96b1-80735f83e3bd.png)
![image](https://user-images.githubusercontent.com/55415231/232656991-cbd743e1-ae22-43d2-b1d3-8929a253c86d.png)

Next I'll add a few more:

![image](https://user-images.githubusercontent.com/55415231/232657182-280fb217-bf4a-484b-aec8-25bfa8f80b68.png)

Now we can view the numbers and make sure it matches our first one:

![image](https://user-images.githubusercontent.com/55415231/232657463-283721f8-77a7-4e31-a657-48ad2419bc7f.png)

As expected, it matches our 6039. Now I'll pop that and the mystery of the next number I added will be solved:

![image](https://user-images.githubusercontent.com/55415231/232657602-482cd458-520f-4517-adad-d84b24e51ce0.png)

![image](https://user-images.githubusercontent.com/55415231/232657653-078335dc-8ad5-4b45-942b-345853edbcb1.png)

As we can see, there are now only three integers in the queue:

![image](https://user-images.githubusercontent.com/55415231/232657922-cd6acffd-f21c-4d1b-a9bc-d0f3dce06e59.png)

Finally after popping the rest from the queue, if we try to pop again, we will get a message indicating that it is already empty.

![image](https://user-images.githubusercontent.com/55415231/232658097-73bf4929-b316-4e72-8e69-4991b6bffc3b.png)
