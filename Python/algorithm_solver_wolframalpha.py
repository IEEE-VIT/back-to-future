import wolframalpha

app_id="your_wolframalpha_app_id"
client = wolframalpha.Client('your_wolframalpha_client_id')
queryfromuser = input("Query: ")
res = client.query(queryfromuser)
answer = next(res.results).text
print(queryfromshaun)
print(answer)
