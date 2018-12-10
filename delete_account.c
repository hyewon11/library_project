
void user_leave(client_node *user){      //회원 탈퇴
  int check=0;
  char answer;
  client_node *ctmp=user;
  client_node *prev=head_client;
  borrow_node *btmp=head_borrow;

  while(1){
    printf("탈퇴를 하시겠습니까?(Y/N):\n");
    scanf("%c",&answer);
    if((answer=='Y')||(answer=='y')||(answer=='N')||(answer=='n')){
      break;
    }
    printf("다시 입력하세요.\n");
  }

  if((answer=='N')||(answer=='n')){
    printf("초기 메뉴로 돌아갑니다.\n");
    return;
  }
  else if((answer=='Y')||(answer=='y')){
    printf("탈퇴를 진행합니다.\n");
  }

  while(btmp->next!='\0'){    // 대여중인 목록 있는지 확인
    if(btmp->student_num==user->std_num){
      printf("반납할 책이 남아 있습니다.\n반납 후 다시 시도하세요.\n");
      check=1;
      break;
    }
    btmp=btmp->next;
  }

  if(check==1){
    return;
  }

  else{
    if(ctmp==head_client){
      head_client = ctmp->next;
      free(ctmp);
    }
    else if(ctmp->next == NULL){
      while(prev->next==user){
        prev=prev->next;
      }
      free(ctmp);
      prev->next=NULL;
    }
    else{
      while(prev->next!=user){
        prev=prev->next;
      }
      prev->next=ctmp->next;
      free(ctmp);
      printf("탈퇴되었습니다.\n");
    }
    client_restore();
    return;

  }
}

void client_restore(){        //client.txt에 다시 저장
  client_node *tmp=head_client;
  FILE *client;
  client = fopen("client.txt","w");
  while(1){
    fprintf(client,"%d|%s|%s|%s|%s\n",tmp->std_num,tmp->PW,tmp->name,tmp->address,tmp->Phone_num);
    if(tmp->next==NULL){break;}
    tmp = tmp->next;
  }
}
