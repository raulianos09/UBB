using System;

namespace AsyncTasks
{
    public class HttpParser
    {
        public const int Port = 80;
        public static string GetRequestString(string hostname, string endpoint)
        {
            return "GET " + endpoint + "HTTP/1.1\r\nHost: " + hostname + "\r\nConnection: Close\r\n\r\n";
        }
        
        public static int GetContentLength(string responseContent)
        {
            var contentLength = 0;
            var respLines = responseContent.Split('\r', '\n');
            foreach (var respLine in respLines)
            {
                var headDetails = respLine.Split(':');

                if (string.Compare(headDetails[0], "Content-Length", StringComparison.Ordinal) == 0)
                {
                    contentLength = int.Parse(headDetails[1]);
                }
            }

            return contentLength;
        }
        
        public static bool ResponseHeaderObtained(string responseContent)
        {
            return responseContent.Contains("\r\n\r\n");
        }
        
        public static string GetResponseBody(string responseContent)
        {
            var result = responseContent.Split(new[] {"\r\n\r\n"}, StringSplitOptions.RemoveEmptyEntries);
            return result.Length > 1 ? result[1] : "";
        }
    }
}