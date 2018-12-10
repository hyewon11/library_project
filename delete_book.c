
void delete_book(){
  book_node *tmp=head_book,*now=head_book;
  int search_num,delete_num,i=0,num[10];
  char search_name[100],y_n[10];
  long long int book_isbn;

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
  }
  else{
    printf("ISBN을 입력하세요: ");
    scanf("%lld",&book_isbn);

    while(1){
      if(book_isbn==tmp->ISBN){
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
  }

  if(i==0){
    printf("해당 도서는 존재 하지 않습니다.\n");
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
    printf("\n도서명: %s\n",now->book_name);
    printf("출판사: %s\n",now->book_publisher);
    printf("저자명: %s\n",now->book_writer);
    printf("ISBN: %lld\n",now->ISBN);
    printf("소장처: %s\n\n",now->locate_place);
  }

  tmp = head_book;
  now = head_book;
  printf("삭제할 도서의 번호를 입력하세요 : ");
  scanf("%d",&delete_num);
  while(1){
    if(delete_num==tmp->book_num){
      break;
    }
    else if(tmp->next==NULL){
      printf("해당 번호의 도서가 없습니다.\n");
      break;
    }
    tmp = tmp->next;
  }

  if(tmp->yes_or_no=='N'){
    printf("이 도서는 삭제할 수 없습니다.\n");
    return;
  }
  else{
    if(tmp==head_book){
      head_book = tmp->next;
      free(tmp);
    }
    else if(tmp->next == NULL){
      while(now->next!=tmp){
        now = now->next;
      }
      free(tmp);
      now->next =NULL;
    }
    else{
      while(now->next!=tmp){
        now=now->next;
      }
      now->next = tmp->next;
      free(tmp);
    }
    printf("이 도서는 삭제 되었습니다.\n");
    book_restore();
  }
  return;
}

void book_restore(){
  FILE *book;
  book_node *tmp = head_book;
  book=fopen("book.txt","w");
  while(1){
    fprintf(book,"%d|%s|%s|%s|%lld|%s|%c\n",tmp->book_num,tmp->book_name,tmp->book_publisher,tmp->book_writer,tmp->ISBN,tmp->locate_place,tmp->yes_or_no);
    if(tmp->next==NULL){break;}
    tmp = tmp->next;
  }
}
