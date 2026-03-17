#include "CardShop.hpp"
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


/**
  @pre  : the input file is in csv format: "name,type,level_rank,race,attribute,atk,def"
  @param: the name of the input file
  @post:  Reads the input file and adds pointers to YGOCard objects 
          instantiated with the information read from the file. 
    */
CardShop::CardShop(std::string input_file_name) 
{
  std::ifstream fin(input_file_name);
  if (fin.fail())
  {
    std::cerr << "File cannot be opened for reading. \n";
    exit(1); // exit if failed to open the file
  }
  //we don't use the first line
  std::string ignore;
  getline(fin, ignore);

  //the columns of the csv associated with the data members
  std::string name, type, race, attribute;
  int level_rank, atk, def;

  std::string temp_string;
  int temp_int;
  int item_counter = 0;
  while (getline(fin, temp_string, ','))
  {
    name = temp_string;

    getline(fin, type, ',');
  
    getline(fin, temp_string, ',');
    std::istringstream(temp_string) >> temp_int;
    level_rank = temp_int;

    getline(fin, race, ',');

    getline(fin, attribute, ',');

    getline(fin, temp_string, ',');
    std::istringstream(temp_string) >> temp_int;
    atk = temp_int;

    getline(fin, temp_string);
    std::istringstream(temp_string) >> temp_int;
    def = temp_int;

    //create new card
    YGOCard *card_ptr = new YGOCard(name, type, level_rank, race, attribute, atk, def);

    //add to linked list and increment counter
    insert(item_counter++, card_ptr);
  }
}

//@post: removes all cards from the shop
//Deallocate and delete items
void CardShop::clear()
{
  for (int i = 0; i < item_count_; i++)
  {
    YGOCard *ptr = getItem(i);
    delete ptr;
    ptr = nullptr;
  }
  DoublyLinkedList::clear();
}

//destructor
CardShop::~CardShop()
{
  clear();
}

//@post: displays information of all cards in the shop, one per line
void CardShop::display()
{
  for (int i = 0; i < item_count_; i++)
  {
    getItem(i)->display();
  }
}

  //@param: the index of the first card to be displayed
  //@param: the index of the last card to be displayed
  //@post: displays the names of all cards in the shop with startRange and endRange, 
  //       inclusive, one per line
void CardShop::displayName(int startRange, int endRange)
{
  for (int i = startRange; i <= endRange; i++)
  {
    getItem(i)->displayName();
    if (i != endRange)
    {
      std::cout << ", ";
    }
    else
    {
      std::cout << std::endl;
    }
  }
}


//@return:  true if all the cards in rhs are equal to the cards in the shop, false otherwise
bool CardShop::operator==(const CardShop &rhs) const
{
  if (getLength() != rhs.getLength())
  {
    return false;
  }
  for (int i = 0; i < getLength(); i++)
  {
    if (*(getPointerTo(i)->getItem()) == *(rhs.getPointerTo(i)->getItem()))
    {
    }
    else
    {
      return false;
    }
  }
  return true;
}



template<typename Comparator>
int CardShop::bubbleSort(Comparator comp, std::string key){
  int count = getLength();                //get length of doublylinkedlist
  
  bool swapped = true;                    //set swapped to true for optimization
  int pass = 1;                           //number of swaps
  int swap_count = 0;                     // swap counter to return
  while(swapped && (pass < count)){       //do if a swap occurred before and the pass is less than count
    swapped = false;                      //make false in order to set to true if a swap occurrs
    for(int i = 0; i < count - pass; i++){
      if(key == "atk"){
        if(comp(getPointerTo(i+1)->getItem()->getAtk(), getPointerTo(i)->getItem()->getAtk())){ //comparison
          swapped = true;
          swap(i, i+1);
          swap_count++;
        }
      }
      else if(key == "def"){
        if(comp(getPointerTo(i+1)->getItem()->getDef(), getPointerTo(i)->getItem()->getDef())){
          swapped = true;
          swap(i, i+1);
          swap_count++;
        }
      }
    }
    pass++;
  }
  return swap_count;                          //return the number of swaps
}
  
template<typename Comparator>
int CardShop::insertionSort(Comparator comp, std::string key){
  int count = getLength();                    //get the doublylinkedlist length
  int swap_count = 0;                         //counter for the number of swaps
  for(int i = 1; i < count; i++){
    int current = i;                          //index of object we are sorting
    if(key == "atk"){
      while((current > 0) && comp(getItem(current)->getAtk(), getItem(current-1)->getAtk())){     //while object is not at beginning and it is less than item behind it
        swap(current-1, current);             //swap the previous element with one in front
        swap_count++;                         //increase swap count
        current--;                            //current goes down by one because we are comparing object with elements before it
      }
    }
    else if(key == "def"){
      while((current > 0) && comp(getItem(current)->getDef(), getItem(current-1)->getDef())){
        swap(current-1, current);
        swap_count++;
        current--;
      }
    }
  }
  return swap_count;                          //return swap count
}

template<typename Comparator>
void CardShop::merge(const Comparator comp, const std::string key, int l_index, int mid, int r_index){    //merges right and left
  int ff_list = l_index;                                        //first array first index
  int fl_list = mid;                                            //first array last index
  int sf_list = mid+1;                                          //second array first index
  int sl_list = r_index;                                        //second array last index
  int tempindex = ff_list;                                      //temp index going to start at left index
  
  YGOCard* temp[r_index+1];                                     //temporary array with size right index +1 because index starts at 0
  while((ff_list <= fl_list) && (sf_list <= sl_list)){          //while the first or second array is not completly done
    if(key == "atk"){
      if(comp(getPointerTo(ff_list)->getItem()->getAtk(), getPointerTo(sf_list)->getItem()->getAtk())){     //comparison
        temp[tempindex] = getPointerTo(ff_list++)->getItem();   //if first array number bigger put that in temp first
        //ff_list++;
        tempindex++;                                            //increase temp index
      }
      else{
        temp[tempindex] = getPointerTo(sf_list++)->getItem();  //second array number goes instead
        //sf_list++;
        tempindex++;                                            //increase temp index
      }
    }
    else if(key == "def"){        //same as atk but for def
      if(comp(getPointerTo(ff_list)->getItem()->getDef(), getPointerTo(sf_list)->getItem()->getDef())){
        temp[tempindex] = getPointerTo(ff_list++)->getItem();
        //ff_list++;
      }
      else{
        temp[tempindex] = getPointerTo(sf_list++)->getItem();
        //sf_list++;
      }
      tempindex++;
    }
  }

  while(ff_list <= fl_list){                  //if second array finishes before first, append rest of first array to temp
    temp[tempindex] = getPointerTo(ff_list++)->getItem();
    //ff_list++;
    tempindex++;
  }
  while(sf_list <= sl_list){                  //if first array finishes before second, append rest of second array to temp
    temp[tempindex] = getPointerTo(sf_list++)->getItem();
    //sf_list++;
    tempindex++;
  }
  for(int index = l_index; index <= r_index; index++){      //loop to rewrite list with sorted array
    this->getPointerTo(index)->setItem(temp[index]);
  }
}

template<typename Comparator>
void CardShop::divide(const Comparator comp, const std::string key, int l_index, int r_index, int &merge_count){
  if(l_index < r_index){                                  //the right index must be bigger than the left index, it will be 1 when stop
  int mid = l_index + ((r_index - l_index) / 2);          //finds midpoint, accounts for if left index is not 0
  divide(comp, key, l_index, mid, merge_count);           //keep dividing left side
  divide(comp, key, mid+1, r_index, merge_count);         //keep dividing right side
  merge(comp, key, l_index, mid, r_index);                //merge right and left
  merge_count++;                                          //merge counter +1 , passs by reference
  }
}

template<typename Comparator>
int CardShop::mergeSort(Comparator comp, std::string key){
  int merge_count = 0;                                    //counting number of merges, pass by reference
  divide(comp, key, 0, getLength()-1, merge_count);       //start dividing up the list
  return merge_count;                                     //return the merge count
}



template<typename Comparator>
void CardShop::sorting(const Comparator comp, const std::string key, int pivot){
  


}


template<typename Comparator>
void CardShop::sort(const Comparator comp, const std::string key, int l_index, int r_index){

  int pivot = r_index;
  int l = -1;

  for(int i = 0; i < r_index; i++){
    if(comp(getPointerTo(r_index)->getItem()->getAtk(),getPointerTo(i)->getItem()->getAtk())){
      l++;
      swap(l, i);
    }
  }
  swap(l+1, pivot);
  sort(comp, key, l_index, l);
  sort(comp, key, pivot+1, r_index);

  


}


template<typename Comparator>
int CardShop::quickSort(Comparator comp, std::string key){
  sort(comp, key, 0, getLength()-1);


  return 0;

}