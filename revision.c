
void revision(client_node *now){       //회원 정보 수정
  int num;
  printf("1.비밀번호 수정\t2. 주소 수정\t3. 전화번호 수정\n");//비밀번호,주소,전화번호수정
  scanf("%d",&num);
  if(num==1){
    printf("수정할 비밀번호를 입력하세요 :");
    scanf("%s",now->PW);
    client_restore();
    printf("수정되었습니다.\n");
  }
  else if(num==2){
    printf("주소를 입력하세요 :");
    scanf(" %[^\n]",now->address);
    client_restore();
    printf("수정되었습니다.\n");
  }
  else if(num==3){
    printf("수정할 전화 번호를 입력하세요 :");
    scanf(" %[^\n]s",now->Phone_num);
    client_restore();
    printf("수정되었습니다.\n");
  }
  else{
    printf("잘못 입력하셨습니다.");
  }

  return;
}
