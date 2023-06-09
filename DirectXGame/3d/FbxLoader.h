﻿#pragma once

#include "fbxsdk.h"

#include <d3d12.h>
#include <d3dx12.h>
#include<string>

class FbxLoader
{
private:

	using string = std::string;

public:
	/// <summary>
	/// シングルトンインスタンスの取得
	/// </summary>
	/// <returns>インスタンス</returns>
	static FbxLoader* GetInstance();

	static const string baseDirectory;

	void Initialize(ID3D12Device* device);

	void Finalize();

	void LoadModelFromFile(const string& modelName);

private:
	// privateなコンストラクタ（シングルトンパターン）
	FbxLoader() = default;
	// privateなデストラクタ（シングルトンパターン）
	~FbxLoader() = default;
	// コピーコンストラクタを禁止（シングルトンパターン）
	FbxLoader(const FbxLoader& obj) = delete;
	// コピー代入演算子を禁止（シングルトンパターン）
	void operator=(const FbxLoader& obj) = delete;

	ID3D12Device* device = nullptr;

	FbxManager* fbxManager = nullptr;

	FbxImporter* fbxImporter = nullptr;
};