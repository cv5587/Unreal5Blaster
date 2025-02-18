// Fill out your copyright notice in the Description page of Project Settings.
//�󸶳� ���� �÷��̾ �κ� �����߳� Ȯ��

#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	//�α��� �ϰ� ó������ �����ϰ� �÷��̾ ������ �ִ� ����
	Super::PostLogin(NewPlayer);

	//�÷��̾� �迭 �޾ƿ�. ������� Ȯ��
	int32 NumberOfPlayer = GameState.Get()->PlayerArray.Num();

	if (NumberOfPlayer == 2)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			bUseSeamlessTravel = true;
			World->ServerTravel(FString("/Game/Maps/BalsterMap?listen"));
		}
	}

}
