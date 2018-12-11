int main(){
int choice_num, hakbun, book_num_input,i=0;
long long ISBN_num;
char answer, name[50];;
client_node *c_tmp = head_client;
book_node *b_tmp = head_book;
book_node *b_now = head_book;
borrow_node *r_tmp= head_borrow;

printf(">> 도서 대여 <<\n");
printf("1. 도서명 검색    2. ISBN 검색\n\n");
printf("검색 번호를 입력하세요:");
while(1){
  scanf("%d",&search_num);
  if(search_num==1||search_num==2){
    break;
  }
  else{
    printf("잘못 입력했습니다. 다시 입력하세요. : ");
  }
}
if(search_num==1){
  printf("도서명을 입력하세요: ");
  scanf("%[^\n]",search_name);
  while(1){
    if(strcmp(b_tmp->book_name,search_name)==0){
      b_now = b_tmp;
      num[i]=b_tmp->book_num;
      y_n[i]=b_tmp->yes_or_no;
      i++;
    }
    if(b_tmp->next==NULL){
      break;
    }
    b_tmp=b_tmp->next;
  }
}
else{
  printf("ISBN을 입력하세요: ");
  scanf("%lld",&book_isbn);

  while(1){
    if(book_isbn==b_tmp->ISBN){
      b_now = b_tmp;
      num[i]=b_tmp->book_num;
      y_n[i]=b_tmp->yes_or_no;
      i++;
    }
    if(b_tmp->next==NULL){
      break;
    }
    b_tmp=b_tmp->next;
  }
}

if(i==0){
  printf("해당 도서는 존재 하지 않습니다.\n");
  return;
}
else{
  printf("\n>> 검색 결과 <<\n");
  printf("도서 번호 :");
  while(1){
    if(i==1){
      printf("%d(삭제 가능 여부 : %c)\n",num[0],y_n[0]);
      break;
    }
    printf("%d(삭제 가능 여부 : %c),",num[i-1],y_n[i-1]);
    i--;
  }
  printf("\n도서명: %s\n",b_now->book_name);
  printf("출판사: %s\n",b_now->book_publisher);
  printf("저자명: %s\n",b_now->book_writer);
  printf("ISBN: %lld\n",b_now->ISBN);
  printf("소장처: %s\n\n",b_now->locate_place);
}

printf("학번을 입력하세요:");
scanf("%d",&hakbun);
getchar();
while(1){
    if(hakbun == c_tmp->std_num)
        break;
    if(c_tmp->next == NULL){
        printf("없는 사용자입니다.\n\n");
        return;
    }
    c_tmp = c_tmp->next;
}
printf("도서번호를 입력하세요:");
scanf("%d",&book_num_input);
getchar();
b_tmp=head_book;
while(1){
  if(book_num_input==b_tmp->book_num){
    break;
  }
  else if(b_tmp->next==NULL){
    printf("해당 번호의 도서가 없습니다.\n");
    break;
  }
  b_tmp = b_tmp->next;
}
if(b_tmp->next!=NULL){
printf("\n이 도서를 대여합니까?");
scanf("%c",&answer);
getchar();
if(answer == 'Y' || answer == 'y'){
    b_tmp->yes_or_no = 'N';
    book_node *newnode=(book_node *)malloc(sizeof(book_node));
    newnode->student_id = hackbun;
    newnode->book_num = b_tmp->book_num;
    newnode->borrow_time = time();
    newnode->return_time = newnode->borrow_time + 60*60*24*30;
    while(r_tmp->next==NULL){
      r_tmp=r_tmp->next;
    }
    r_tmp -> next = newnode;
    printf("도서가 대여 되었습니다.\n");
    borrow_restore();
    return;
}
else if(answer == 'N' || answer == 'n'){
    printf("대여가 안되었습니다\n");
    return;
}
else{
  printf("잘못입력하셨습니다\n\n");
}
  return;
}
}
void borrow_restore(){
  FILE *borrow;
  borrow_node *tmp = head_borrow;
  borrow = fopen("borrow.txt","w");
  while(1){
    fprintf(borrow, "%d|%d|%d|%d",tmp->student_num,tmp->book_num,(int)tmp->borrow_time,(int)return_time);
    if(tmp->next==NULL){break;}
    tmp=tmp->next;
  }
}
