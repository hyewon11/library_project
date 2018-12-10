int main(){
  book_node *tmp,*now;
  int search_num,delete_num,i=0;
  int num[10]=0,y_n[10]=0;
  char search_name[100];
  printf(">> 도서 삭제 <<\n");
  printf("1. 도서명 검색\t2. ISBN 검색\n\n");
  printf("검색 번호를 입력하세요.: ");
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
    printf("%s\n",search_name);
    while(1){
    if(strcmp(tmp->book_name,search_name)==0){
      now = tmp;
      num[i]=tmp->book_num;
      y_n[i]=tmp->yes_or_no;
      i++;
    }
    if(tmp->next==NULL){
      break;
    }
    tmp=tmp->next;
  }
  if(i==0){
    printf("해당 도서는 존재 하지 않습니다.\n");
  }
  else{
    printf(">> 검색 결과 <<\n");
    printf("도서 번호 :");
    while(1){
      if(i==1){
        printf("%d(삭제 가능 여부 : %c)\n",num[0],y_n[0]);
        break;
      }
      printf("%d(삭제 가능 여부 : %c),",num[i-1],y_n[i-1]);
      i--;
    }
    printf("\n도서명: %s\n",now->book_name);
    printf("출판사: %s\n",now->book_publisher);
    printf("저자명: %s\n",now->book_writer);
    printf("ISBN: %lld\n",now->ISBN);
    printf("소장처: %s\n",now->locate_place);
  }
    printf("삭제할 도서의 번호를 입력하세요: ");
    scanf("%d",&delete_num);
    while(1){
      if(btmp->book_num==delete_num){
        printf("삭제되었습니다.");
        break;
      }
    }
  }
  else if(search_num==2){
    printf("ISBN을 입력하세요: ");
    scnaf("%s",search_name);
    p
  }

}
