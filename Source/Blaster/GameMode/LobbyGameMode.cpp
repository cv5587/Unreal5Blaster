// Fill out your copyright notice in the Description page of Project Settings.
//얼마나 많은 플레이어가 로비에 연결했나 확인

#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	//로그인 하고 처음으로 안전하게 플레이어를 받을수 있는 공간
	Super::PostLogin(NewPlayer);

	//플레이어 배열 받아옴. 명몇인지 확인
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
