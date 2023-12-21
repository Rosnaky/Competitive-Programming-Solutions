n = int(input())

streams = []

for i in range(n):
    streams.append(int(input))

cmd = int(input())

while (cmd != 77):
    if (cmd == 99):
        stream = int(input())
        flow = int(input())

        streams.insert(stream, streams[stream] - streams[stream]*flow/100)
        streams[stream] *= flow/100;

    elif (cmd == 88):
        stream = int(input())
        streams[stream-1] += streams[stream]
        streams.pop(stream)

    cmd = int(input())

for x in streams:
    print(x, end=" ")