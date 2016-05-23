# Million-number
AIT

1.	Yêu cầu đề bài
	-	Sắp xếp 1 triệu số nguyên có dấu 32 bit
	-	Giới hạn bộ nhớ là 3MB
2.	Thuật toán – phương pháp xử lý
	Vì bộ nhớ giới hạn bởi 3Mb, mà 1 số nguyên 32 bit = 4byte. Vậy 1 triệu số nguyên đầu vào tương ứng với 4*1000000 ~ 4Mb > 3Mb.
	Thuật toán xử lý sẽ là phương pháp chia nhỏ:
	-	Thuật toán sẽ chia 1 triệu phần tử thành 4 phần.
	-	Mỗi phần sẽ được sắp xếp theo thứ tự rồi ghi vào file testx.txt.
	-	Sử dụng merge để kết hợp 4 file testx.txt thành file output.txt.
3.	File test và ans
	File test được tạo random với giá trị từ -2000000000 đến 2000000000.
	Với 1 triệu phần tử.
4.	Chương trình kiểm tra đáp án
	Chương trình kiểm tra đáp án chạy từ đầu file ans.txt đến cuối file.
	Nếu như giá trị sau > trước thì sẽ dừng chương trình vào báo sai.
