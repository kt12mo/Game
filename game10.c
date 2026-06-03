#include <stdio.h>
#include <string.h>

int main(void) {
    char input[50];
    int n;

 printf("問題は3つあります。好きな番号を選んで下さい\n3番はサッカーが好きな人におすすめです！\n 1 2 3 ") ;
 scanf("%d",&n);
printf("質問はすべてで6つあります。\n私が思い浮かべるものと被らないように、頑張って下さい！\n");

 if(n==1){
        printf("なにか動物を思い浮かべてください\n");
        scanf("%s", input);

        if (strcmp(input, "イヌ") == 0 || strcmp(input,"いぬ")==0 || strcmp(input,"犬")==0) {
            printf("私もイヌを思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は イヌ を思い浮かべました。\n");
        }


        printf("次の質問です！\nなにか野菜を思い浮かべてください\n");
        scanf("%s",input);

        if (strcmp(input,"にんじん")==0 || strcmp(input,"人参")==0 || strcmp(input,"ニンジン")==0) {
            printf("私も にんじん を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は にんじん を思い浮かべました。\n");
        }

        printf("次の質問です！\n夏といったら？\n");
        scanf("%s",input);

        if (strcmp(input, "海")==0) {
            printf("私も 海 を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は 海 を思い浮かべました。\n");
        }
    

        printf("次の質問です！\nなにか哺乳類を思い浮かべてください！\n");
        scanf("%s",input);

        if (strcmp(input, "ペンギン")==0 || strcmp(input,"ぺんぎん")==0) {
            printf("私も ペンギン を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は ペンギン を思い浮かべました。\n");
        }
         
         printf("次の質問です！\nなにかスポーツを思い浮かべてください！\n");
        scanf("%s",input);

        if (strcmp(input, "バレー")==0 || strcmp(input,"バレーボール")==0) {
            printf("私も バレーボール を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は バレーボール を思い浮かべました。\n");
        }
         
        printf("最後の質問です！\nヨーロッパの国を思い浮かべてください！\n");
        scanf("%s",input);

        if (strcmp(input, "フランス")==0) {
            printf("私も フランス を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は フランス を思い浮かべました。\nあなたの勝ちです！！"); 
        }

    return 0;
 }



if(n==2){
        printf("牛丼が有名なチェーン店を思い浮かべて下さい\n");
        scanf("%s", input);

        if (strcmp(input, "吉野家") == 0){
            printf("私も 吉野家 を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は 吉野家 を思い浮かべました。\n");
        }


        printf("次の質問です！\nラーメンの味を一種類を思い浮かべてください\n");
        scanf("%s",input);

        if (strcmp(input,"豚骨")==0 || strcmp(input,"豚骨ラーメン")==0 || strcmp(input,"ニンジン")==0) {
            printf("私も 豚骨 を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は 豚骨ラーメン を思い浮かべました。\n");
        }

        printf("次の質問です！\n青森県といったら？\n");
        scanf("%s",input);

        if (strcmp(input, "ねぶた")==0 || strcmp(input,"ねぶた祭り")==0) {
            printf("私も ねぶた を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は ねぶた を思い浮かべました。\n");
        }
    

        printf("次の質問です！\nマクドナルドのバーガーをひとつを思い浮かべてください！\n");
        scanf("%s",input);

        if (strcmp(input, "てりやき")==0 || strcmp(input,"照り焼き")==0 || (strcmp(input, "てりやきバーガー")==0) || (strcmp(input, "照り焼きバーガー")==0)) {
            printf("私も てりやきバーガー を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は てりやきバーガー を思い浮かべました。\n");
        }
         
         printf("次の質問です！\nサッカー日本代表の選手を一人思い浮かべてください！\n");
        scanf("%s",input);

        if (strcmp(input, "久保")==0 || strcmp(input,"久保建英")==0 || strcmp(input, "久保選手")==0 || strcmp(input,"久保建英選手")==0) {
            printf("私も 久保選手 を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は 久保選手 を思い浮かべました。\n");
        }
         
        printf("最後の質問です！\n尾崎豊の曲を一曲思い浮かべてください！\n");
        scanf("%s",input);

        if (strcmp(input, "OH MY LITTLE GIRL")==0 || strcmp(input, "oh my little girl")==0 || strcmp(input, "オウマイリトルガール")==0 || strcmp(input, "Oh my little girl")==0 || strcmp(input, "Oh My Little Girl")==0) {
            printf("私も OH MY LITTLE GIRL を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は OH MY LITTE GIRL を思い浮かべました。\nあなたの勝ちです！！"); 
        }

    return 0;
 }


if(n==3){
        printf("現役サッカースペイン代表の選手を一人思い浮かべてください\n");
        scanf("%s", input);

        if (strcmp(input, "モラタ") == 0){
            printf("私も モラタ を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は モラタ を思い浮かべました。\n");
        }


        printf("次の質問です！\nコロンビア代表の選手を一人を思い浮かべてください\n");
        scanf("%s",input);

        if (strcmp(input,"ルイスディアス")==0 || strcmp(input,"ディアス")==0){
            printf("私も ルイスディアス を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は ルイスディアスを思い浮かべました。\n");
        }

        printf("次の質問です！\n現役右サイドバックの選手を一人思い浮かべてください\n");
        scanf("%s",input);

        if (strcmp(input, "ウォーカー")==0 || strcmp(input,"カイルウォーカー")==0) {
            printf("私も ウォーカー を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は ウォーカー を思い浮かべました。\n");
        }
    

        printf("次の質問です！\nミラクルレスターの選手を一人思い浮かべてください！\n");
        scanf("%s",input);

        if (strcmp(input, "マフレズ")==0 || strcmp(input,"リヤドマフレズ")==0) {
            printf("私も マフレズ を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は マフレズ を思い浮かべました。\n");
        }
         
         printf("次の質問です！\nヨーロッパリーグ優勝経験のあるクラブを一つ思い浮かべてください！\n");
        scanf("%s",input);

        if (strcmp(input, "セビージャ")==0 ) {
            printf("私も セビージャ を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は セビージャ を思い浮かべました。\n");
        }
         
        printf("最後の質問です！\nウルグアイ代表の選手を一人思い浮かべてください！\n");
        scanf("%s",input);

        if (strcmp(input, "カバー二")==0 || strcmp(input, "エディンソンカバーニ")==0) {
            printf("私も カバーに を思い浮かべました。\nあなたの負けです！\n");
            return 0;
        } else {
            printf("私は カバー二 を思い浮かべました。\nあなたの勝ちです！！"); 
        }

    return 0;
 }


}


