# Million-number
AIT

1.	Yêu cầu đề bài
	-	Sắp xếp 1 triệu số nguyên có dấu 32 bit
	-	Giới hạn bộ nhớ là 3MB
2.	Thuật toán – phương pháp xử lý
	Vì bộ nhớ giới hạn bởi 3Mb, mà 1 số nguyên 32 bit = 4byte. Vậy 1 triệu số nguyên đầu vào tương ứng với 4*1000000 ~ 4Mb > 3Mb.
	Thuật toán xử lý sẽ là phương pháp chia nhỏ:
	-	Lấy 2 đầu mút của dãy.
	-	Chia dãy thành 500 dãy con.
	-	Sẽ lấy từng dãy con đem bỏ vào mảng.
	-	Sẽ sắp xếp từng mảng theo Heap_sort. Thuật toán này sẽ tốn bộ nhớ O(1).

	Tính khoảng giá trị của dãy delta = max – min.
	Khoảng giá trị trung bình của 500 dãy là value = delta/500;
	Cách lấy giới hạn của mỗi khoảng dãy con
	
	-	minarray1 = min  -> maxarray1 = minarray1 + value
	-	minarray2 = maxarray1  -> maxarray2 = minarray2 + value
	-	. . . 
	-	minarray500 = maxarray499 -> maxarray500 = max + 1
	
	Mỗi dãy con sẽ được sắp xếp theo thuật toán heap_sort.
	Sau khi sắp xêp dãy con sẽ ghi dãy con ra file ans.txt.
3.	File test và ans
	File test được tạo random với giá trị từ -2*1000000000 đến 2*1000000000.
	Với 1 triệu phần tử.
4.	Chương trình kiểm tra đáp án
	Chương trình kiểm tra đáp án chạy từ đầu file ans.txt đến cuối file.
	Nếu như giá trị sau > trước thì sẽ dừng chương trình vào báo sai.
