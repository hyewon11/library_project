void return_book(){
  borrow_node *rtmp=head_borrow,*r_prev=head_borrow;
  book_node *btmp=head_book;
  int student_id,return_book,i=0,num[10];
  char answer;
  printf("학번을 입력하세요: ");
  scanf("%d",&student_id );
  printf("\n>> 회원의 대여 목록 <<\n");
  while(1){
    if(rtmp->student_num==student_id){
      printf("도서번호: %d\n",rtmp->book_num);
      num[i]=rtmp->book_num;
      i++;
      while(1){
        if(rtmp->book_num==btmp->book_num){
          printf("도서명: %s\n\n",btmp->book_name);
          break;
        }
        if(btmp->next==NULL){break;}
        btmp = btmp->next;
      }
      printf("대여일자:%s\n",ctime(&(rtmp->borrow_time)));
      printf("반납일자:%s\n\n",ctime(&(rtmp->return_time)));
    }
    if(rtmp->next==NULL){break;}
    rtmp = rtmp->next;
  }

  printf("반납할 도서번호를 입력하세요: ");
  scanf("%d",&return_book);
  getchar();
  while(1){
    if(i==0){break;}
    if(num[i]==return_book){
      break;
    }
    i--;
  }

  if(i>0){
    while(1){
    printf("도서 반납처리를 할까요?: ");
    scanf("%c",&answer);
    if((answer=='Y')||(answer=='y')){
      rtmp=head_borrow;
      while(1){
        if(return_book==rtmp->book_num){
          break;
        }
        rtmp = rtmp->next;
      }

      if(rtmp==head_borrow){
        head_borrow=rtmp->next;
        free(rtmp);
      }
      else if(rtmp->next == NULL){
        while(r_prev->next!=rtmp){
          r_prev = r_prev ->next;
        }
        free(rtmp);
        r_prev->next = NULL;
      }
      else{
        while(r_prev->next!=rtmp){
          r_prev=r_prev->next;
        }
        r_prev->next = rtmp->next;
        free(rtmp);
      }

      printf("도서가 반납되었습니다.\n");
      break;
    }
    else if((answer=='N')||(answer=='n')){
      printf("도서 반납을 취소하였습니다.\n");
      break;
    }
    else{
      printf("잘못된 입력입니다.\n");
    }
  }
  return;
}
}
