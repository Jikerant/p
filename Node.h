#pragma once
#include "vector"
#include "iostream"
#include "Error.h"
#include <limits.h>
using namespace std;
template <class T>
class Node {
	vector<vector<T>> data;// stl vector матриц€ 
	int width;
	int height;

public:
	Node() :width(10), height(10) {
		data.resize(height);
		for (int i = 0; i < height; ++i) {
			data[i].resize(width);
		}

	}
	Node(int _width) :width(_width), height(10) {
		data.resize(height);
		for (int i = 0; i < height; ++i) {
			data[i].resize(width);
		}
	}
	Node(int _width, int _height) : width(_width), height(_height) {
		data.resize(height);
		for (int i = 0; i < height; ++i) {
			data[i].resize(width);
		}

	}
	Node(int _width, int _height, const vector<T>& _data) :width(_width), height(_height) {
		data.resize(height);
		for (int i = 0; i < height; ++i) {
			data[i].resize(width);
		}
		if (_data.size() != width * height)throw ErrorBase();


		for (int i = 0; i < height; ++i) {

			for (int j = 0; j < width; ++j) {
				if (_data[i * width + j] > INT_MAX)throw ErrorDerived();

				else data[i][j] = _data[i * width + j];//≥н≥ал≥зац≥€ странна але все в ≥м'€ stl бо це мас≥в ≥значально а так не буде трабл≥в з елементами
			}
		}
	}

	~Node() {//н≥чо  нема бо ≥ не нада stl сам все зробить так то

	}
	Node(const Node& other) :height(other.height), width(other.width), data(other.data) {//взагал≥ так н≥з€ ≥н≥ц≥ал≥зувати але vector творить чудеса,Ps:€ про data


	}
	Node& operator=(const Node& other) {
		if (this != &other) {
			data = other.data; // Copy the matrix data
			width = other.width;
			height = other.height;
		}
		return *this;
	}

	inline int getWidth() const { return width; }//const шоб навен≥ка не зм≥нило данн≥
	inline int getHeight() const { return height; }
	inline void setHeight(int h) { height = h; }
	inline void setWidth(int w) { width = w; }
	inline const vector<vector<T>>& getData() const {
		return data;
	}
	inline vector<vector<T>>& getDataNoConst() {
		return data;
	}
	void setData(const vector<vector<T>>& nData) {
		if (nData.empty()) {
			throw ErrorO();
		}
		int nHeight = nData.size();
		int nWidth = nData[0].size();
		for (const auto& row : nData) {
			if (row.size() != nWidth) {
				throw ErrorBase();
			}
		}
		height = nHeight;
		width = nWidth;
		data = nData;
	}
	inline void reInit(vector<T>& _data) {
		for (int i = 0; i < height; ++i) {

			for (int j = 0; j < width; ++j) {
				if (_data[i * width + j] > INT_MAX)throw ErrorDerived();
				else data[i][j] = _data[i * width + j];
			}
		}
	}
	inline T getElement(int row, int col) const {
		if (row < 0 || row >= height || col < 0 || col >= width) {
			throw ErrorS();
		}
		return data[row][col];
	}

	inline void setElement(int row, int col, T value) {
		if (row < 0 || row >= height || col < 0 || col >= width) {
			throw ErrorS();
		}
		data[row][col] = value;
	}
	void show() {
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				if (i < height && j < width) {
					cout << data[i][j] << " ";
				}
			}
			cout << endl;
		}
	}
};
